long long GCD(long long a, long long b) {
	int nod;
	while (b != 0) {
		nod = b;
		b = a % b;
		a = nod;
	}
	return a;
}

std::pair<long long, long long> reduce(long long m, long long n) {
	int del_max = GCD(std::abs(m), n);

	m = m / del_max;
	n = n / del_max;

	return std::make_pair(m, n);
}

std::tuple<long long, long long, long long> find_lcm(long long n1, long long n2) {
	long long max_del = GCD(n1, n2);

	long long lcm = (n1 * n2)/max_del;
	long long c1 = lcm / n1;
	long long c2 = lcm / n2;

	return std::make_tuple(lcm, c1, c2);
}
