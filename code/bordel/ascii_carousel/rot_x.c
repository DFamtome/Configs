void rot_x(char *s, int x)
{
	int x1 = x;
	int x2 = x;

    x1 %= 26;
	x2 %= 10;

    if (!s || (!x1 && !x2))
    {
        return;
    }

    if (x1 < 0)
    {
        x1 += 26;
    }
	else if (x2 < 0)
	{
		x2 += 10;
	}

    for (int i = 0; s[i] != 0; i++)
    {
        char c = s[i];

        if ('A' <= c && c <= 'Z')
        {
            c = (((c - 'A') + x1) % 26) + 'A';
        }
        else if ('a' <= c && c <= 'z')
        {
            c = (((c - 'a') + x1) % 26) + 'a';
        }
		else if ('0' <= c && c <= '9')
		{
			c = (((c - '0') + x2) % 10) + '0';
		}

        s[i] = c;
    }
}
