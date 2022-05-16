# TODO

def main():
    while True:
        n = int(input("Credit Card Number: "))
        if n > 0:
            break

    count = len(str(n))

    sum = checksum(count, n)

    # Visa
    startswith_VISA16 = n // pow(10, 15)
    if sum % 10 == 0 and count == 16 and startswith_VISA16 == 4:
        print("VISA")
        return 0

    startswith_VISA15 = n // pow(10, 14)
    if sum % 10 == 0 and count == 15 and startswith_VISA15 == 4:
        print("VISA")
        return 0

    startswith_VISA14 = n // pow(10, 13)
    if sum % 10 == 0 and count == 14 and startswith_VISA14 == 4:
        print("VISA")
        return 0

    startswith_VISA13 = n // pow(10, 12)
    if sum % 10 == 0 and count == 13 and startswith_VISA13 == 4:
        print("VISA")
        return 0

    # American Express
    startswith_American_Express_34 = n // pow(10, 13)
    if sum % 10 == 0 and count == 15 and startswith_American_Express_34 == 34:
        print("AMEX")
        return 0

    startswith_American_Express_37 = n // pow(10, 13)
    if sum % 10 == 0 and count == 15 and startswith_American_Express_37 == 37:
        print("AMEX")
        return 0

    # Mastercard
    startswith_American_Express_51 = n // pow(10, 14)
    if sum % 10 == 0 and count == 16 and startswith_American_Express_51 == 51:
        print("MASTERCARD")
        return 0

    startswith_American_Express_52 = n // pow(10, 14)
    if sum % 10 == 0 and count == 16 and startswith_American_Express_52 == 52:
        print("MASTERCARD")
        return 0

    startswith_American_Express_53 = n // pow(10, 14)
    if sum % 10 == 0 and count == 16 and startswith_American_Express_53 == 53:
        print("MASTERCARD")
        return 0

    startswith_American_Express_54 = n // pow(10, 14)
    if sum % 10 == 0 and count == 16 and startswith_American_Express_54 == 54:
        print("MASTERCARD")
        return 0

    startswith_American_Express_55 = n // pow(10, 14)
    if sum % 10 == 0 and count == 16 and startswith_American_Express_55 == 55:
        print("MASTERCARD")
        return 0

    else:
        print("INVALID")


# Checksum using luhn algorithm
def checksum(count, n):
    sum = 0
    for i in range(count):
        # to find each element of credit number
        remainder = n % 10
        n = n // 10

        # starting from last second digit
        if i % 2 != 0:
            # higher than 10 then it is divided two element
            if remainder * 2 >= 10:
                remainder = remainder * 2
                # two element is found using % and /
                sum = sum + remainder % 10 + remainder // 10

            # otherwise it multiplied element is added to sum
            else:
                sum = sum + remainder * 2

        else:
            sum = sum + remainder

    return sum


if __name__ == "__main__":
    main()