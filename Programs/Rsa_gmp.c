#include<gmp.h>
#include<time.h>
#include<fstream>
#include<string.h>
#include<iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	// generate large prime numbers algorithm
	gmp_randstate_t grt;
	 gmp_randinit_default (grt); // Set default random number generating algorithm
	 gmp_randseed_ui (grt, time (NULL)); // Set the current time of the randomization seed

	mpz_t key_p, key_q;
	 mpz_init (key_p); // initialize large prime numbers p and q
	mpz_init(key_q);

	 mpz_urandomb (key_p, grt, 1024); // generates a random number a ^ 0-2 1024
	mpz_urandomb(key_q, grt, 1024);



	//mpz_t key_pp, key_qq;
	 mpz_nextprime (key_p, key_p); // prime number generating function using the built-GMP
	mpz_nextprime(key_q, key_q);
	gmp_printf("%ZX\n\n", key_p);
	gmp_printf("%ZX\n\n", key_q);

	 // p * value of q is calculated, and stored in the n
	mpz_t key_n;
	mpz_init(key_n);
	 mpz_mul (key_n, key_p, key_q); // calculate p * q

	 // Calculation (p-1) * (q-1) and the values ​​in the key_f
	mpz_t key_f;
	mpz_init(key_f);
	mpz_sub_ui(key_p, key_p, 1);
	mpz_sub_ui(key_q, key_q, 1);
	mpz_mul(key_f, key_p, key_q);

	 // Find meet the requirements to e, the public key (e, n) e generally takes three values, 17 and 65 537, we have direct access to e = 65537
	mpz_t key_e;
	mpz_init_set_ui(key_e, 65537);

	 // output public key (e, n)
	gmp_printf("%s (%ZX, %ZX)\n\n\n", "public key is:", key_n, key_e);

	 E // find the inverse element, i.e. ed mod (f) = 1;
	 // gmp comes with a number of requirements on them to solve the inverse function
	mpz_t key_d;
	mpz_init(key_d);
	mpz_invert(key_d, key_e, key_f);
	 gmp_printf ( "% s (% ZX,% ZX) \ n \ n \ n", "private key is:", key_d, key_e); // output private key


	 // encrypt the plaintext m C = m ^ e mod n
	mpz_t M, C;
	mpz_init(C);
	mpz_init_set_ui(M, 1234);
	//mpz_get_str(M, 16, M);
	 mpz_powm (C, M, key_e, key_n); // calculation function C = M ^ e mod n using a modular exponentiation of GMP;
	gmp_printf("%s %ZX\n\n", "the cipertxt is", C);

	 // algorithm decryption function M = C ^ d mod n
	mpz_t M2;
	//mpz_init_set_str(C2,M2,16);
	mpz_init(M2);
	 mpz_powm (M2, C, key_d, key_n); // M using a modular exponentiation calculation function of the GMP = C ^ d mod n;
	gmp_printf("%s %ZX\n\n","the M2 is", M2);

	mpz_clear(key_q);
	mpz_clear(key_p);
	mpz_clear(M);
	mpz_clear(C);
	mpz_clear(M2);
	mpz_clear(key_n);
	mpz_clear(key_f);
	mpz_clear(key_d);
	return 0;
}
