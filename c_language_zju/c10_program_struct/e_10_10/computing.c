extern int Count;

void average(struct student s[])
{
	int i;

	for (i = 0; i < Count; i++)
	{
		s[i].average = (s[i].math + s[i].english + s[i].computer) / 3.0;
	}
}
