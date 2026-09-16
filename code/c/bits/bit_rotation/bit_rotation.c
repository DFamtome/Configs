unsigned char rol(unsigned char value, unsigned char roll)
{
    for (int i = 0; i < roll; i++)
    {
        value = ((128 & value) > 0) | value << 1;
    }
    return value;
}
