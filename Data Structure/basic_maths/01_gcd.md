# GCD (Greatest Common Divisor)

## What actually is GCD (Greatest Common Divisor)

> The Greatest Common Division (GCD) is also know as High Common Factor (HCF) is the greatest number that divides a set of numbers without leaving any reminders.

- [GCD (Greatest Common Divisor)](#gcd-greatest-common-divisor)
  - [What actually is GCD (Greatest Common Divisor)](#what-actually-is-gcd-greatest-common-divisor)
    - [Example](#example)
    - [Usages of GCD](#usages-of-gcd)
  - [Method of Find GCD](#method-of-find-gcd)
    - [1. Euclid's  Algorithm](#1-euclids--algorithm)

### Example

- **GCD** of **gcd(9,12)**
  
  ```txt
  Factor of 9 --> 1, 3, 9
  Factor of 12 --> 1, 2, 3, 4, 6, 12

  --> As we see the greater common factor is "3".
  ```

- **GCD** of **gcd(11, 13)**

  ```txt
  Factor of 11 --> 1, 11
  Factor of 13 --> 1, 13

  --> As we see the greater common factor is "1".
  ```

### Usages of GCD

- Maximum 2 Groups can be formed with each having 2 Stars and 3 Moons.

    ![greatest-common-divisor-01](https://media.geeksforgeeks.org/wp-content/uploads/20241023175707381113/GCD-1---Step-2.webp)

  - **Result:**  GCD of 4 Stars and 6 Moons will be 2. Which means we can divide them into two
groups.

- Find the Maximum Number of Groups to Equally Distribute 6 Candies and 9 Chocolates.

    ![greatest-common-divisor-02](https://media.geeksforgeeks.org/wp-content/uploads/20241023175707135429/GCD-2---Step-2.webp)

  - **Result:** GCD of 6 Candies and 9 Chocolates will be 3.

## Method of Find GCD

- There are multiple method to find GCD:
  1. **Prime Factorization method**
  2. **Euclid's Division Algorithm**
  3. **Binary GCD Algorithm**

---

### 1. Euclid's  Algorithm

> Euclid's Algorithm, It is used to find the **Greatest Common Divisor (GCD)** of two integers. In this algorithm, We repeatedly subtract the larger number by smaller one. Until of the number becomes **zero**.
