/*
	Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
	Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
	- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    string::size_type index;

    index = s.find("AM");
    if (index != string::npos)
    {
        if(s.substr(0,2) == "12")
        {
            s[0] = '0';
            s[1] = '0';
        }
    }
    else
    {
        index = s.find("PM");
        if(s.substr(0,2) != "12")
        {
            int i = atoi(s.c_str()) + 12;
            s[0] = '0' + i / 10;
            s[1] = '0' + i % 10;
        }
    }
    s.erase(index,2);

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
