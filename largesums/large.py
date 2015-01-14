n = int(raw_input());
while n >0:
	str = raw_input();
	k = str.split("+");
	if len(k) == 1:
		m = str.split("-");
		print (long(m[0]) - long(m[1]));
	else:
		print (long(k[0]) + long(k[1]));
	n = n - 1;
