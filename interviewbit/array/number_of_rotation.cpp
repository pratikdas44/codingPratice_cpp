//number of rotation such that string after rotation is same
int findRotations(string str)
{
	// tmp is the concatenated string.
	string tmp = str + str;
	int n = str.length();

	for (int i = 1; i <= n; i++) {

		// substring from i index of original
		// string size.
		string substring = tmp.substr(i, str.size());

		// if substring matches with original string
		// then we will come out of the loop.
		if (str == substring)
			return i;
	}
	return n;
}
