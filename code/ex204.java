class Solution {
	public int countPrimes(int n) {
		int count = 1;

		// No prime number less than 2
		if (n <= 2)
			return 0;


		boolean[] notPrime = new boolean[n];

		for (int i = 3; i < n; i += 2) {
			if (!notPrime[i]) {
				count += 1;

				// Loop through numbers greater than 3 and set those composite number(i * j) to true
				for (int j = 3; i * j < n; j += 2) {
					notPrime[i * j] = true;
				}
			}
		}



		return count;
	}
}
