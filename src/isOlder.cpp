/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int check(int dd, int mm, int yy, char *dob)
{
	int length = 0, index;
	for (index = 0; dob[index] != '\0'; index++)
	{
		length++;
	}
	if (length <= 0 || length>10)
		return -1;
	if (mm <= 0 || mm>12)
		return -1;
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
	{
		if (dd <= 0 || dd>31)
			return -1;
	}
	if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
	{
		if (dd <= 0 || dd>30)
			return -1;
	}
	if (mm == 2)
	{
		if ((yy % 4 == 0))
		{
			if ((yy % 100 == 0) && (yy % 400 == 0))
			{
				if (dd <= 0 || dd>29)
					return -1;
			}
			else
			{
				if (dd <= 0 || dd>29)
					return -1;
			}
		}
		else
		{
			if (dd <= 0 || dd>28)
				return -1;
		}
	}
	return 0;
}
int isOlder(char *dob1, char *dob2) {
	int mm1, mm2, yy1, yy2, dd1, dd2, check_result;
	mm1 = ((dob1[3] - 48) * 10) + (dob1[4] - 48);
	mm2 = ((dob2[3] - 48) * 10) + (dob2[4] - 48);
	dd1 = ((dob1[0] - 48) * 10) + (dob1[1] - 48);
	dd2 = ((dob2[0] - 48) * 10) + (dob2[1] - 48);
	yy1 = ((dob1[6] - 48) * 1000) + ((dob1[7] - 48) * 100) + ((dob1[8] - 48) * 10) + (dob1[9] - 48);
	yy2 = ((dob2[6] - 48) * 1000) + ((dob2[7] - 48) * 100) + ((dob2[8] - 48) * 10) + (dob2[9] - 48);
	check_result = check(dd1, mm1, yy1, dob1);
	if (check_result == -1)
		return -1;
	check_result = check(dd2, mm2, yy2, dob2);
	if (check_result == -1)
		return -1;
	if (yy1<yy2)
		return 1;
	else if (yy1>yy2)
		return 2;
	else if (yy1 == yy2)
	{
		if (mm1>mm2)
			return 2;
		else if (mm1<mm2)
			return 1;
		else if (mm1 == mm2)
		{
			if (dd1<dd2)
				return 1;
			else if (dd1>dd2)
				return 2;
			else if (dd1 == dd2)
				return 0;
		}
	}
}
