#include<stdio.h>
#include<math.h>

int main() {
	int k, d, m, y, i, exp;
	double salary, msalary, pf;
	scanf("%d", &k);
	while (k--) {
		scanf("%d/%d/%d", &d, &m, &y);
		scanf("%lf", &salary);
		scanf("%d", &exp);
		msalary = salary / 12.0;
		pf = 0.0;
		for (i = 1; i <= exp * 12; i++) {
			m = m % 12 + 1;
			pf = pf + msalary * .12;
			if (i % 12 == 0 && i != 48 && i != 96)
				msalary = msalary * 1.12;
			else if (i == 48)
				msalary = msalary * 1.20;
			else if (i == 96)
				msalary = msalary * 1.15;

			if (i >= 12 && i < 36 && m == 4)
				msalary = msalary * 1.11;
			else if (i >= 36 && i < 84 && m == 4)
				msalary = msalary * 1.09;
			else if (i >= 84 && m == 4)
				msalary = msalary * 1.06;
		}
		printf("Final Salary = %.lf\n", ceil(msalary * 12));
		printf("Final Accumulated PF = %.lf\n", ceil(pf));
	}
	return 0;
}