//============================================================================
// Example of using string lists in the flags code lab.
//============================================================================

#include <stdio.h>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <string>
#include <vector>
#include <map>
using namespace std;

//const char* welcome_strings[] = { "abc", "def", "ghi", NULL, };

//======================================================
// Class hierarchy of string filters
//======================================================

// Interface of string filters
class StringFilter {
public:
	virtual ~StringFilter() {
	}

	// Does string match filtering criteria?
	virtual bool matches(const string &) const = 0;

	// Convert a null-terminated string array to a vector of strings
	// and filter it using this object
	vector<string> filter_string_list(const char* strings[]) {
		vector<string> output;
		int count = 0;
		while (strings[count]) {
			const char *s = strings[count];
			if (matches(s)) {
				output.push_back(s);
			}
			count++;
		}
		return output;
	}
};

// Matches all strings
class NoFilter: public StringFilter {
public:
	bool matches(const string &s) const {
		return true;
	}
} NO_FILTER;

// Matches strings that contain a substring
class SubstringFilter: public StringFilter {
public:
	SubstringFilter(const char *substring) :
			sub_string_(substring) {
	}

	bool matches(const string &s) const {
		size_t found = s.find(sub_string_);
		return (found != string::npos);
	}
private:
	const char* sub_string_;
};

// Factory method of filters based on CLI flags
StringFilter* new_string_filter(const string& filter_type, const char* arg) {
	if (filter_type.empty()) {
		return &NO_FILTER;
	} else if (filter_type.c_str() == "substring") {
		return new SubstringFilter(arg);
	} else {
		printf("Unsupported filter type '%s'\n", filter_type.c_str());
		exit(EXIT_FAILURE);
	}
}

//======================================================
// A class that holds multiple string lists
//======================================================

class Dictionary {
	Dictionary(const char *argv[]) {
		filter_ = new_string_filter(argv[0], argv[1]);
	}

	const vector<string>& operator[](const string &key) {
		return map_[key];
	}

	void insert(const string &key, const char* value[],
			bool filter = false) {
		const vector<string> filtered_value =
				filter ? filter_->filter_string_list(value) : value;
		map_[key] = value;
	}

private:
	map<string, vector<string> > map_;
	StringFilter *filter_;
};

int main_string_list() {
	return 0;
}
