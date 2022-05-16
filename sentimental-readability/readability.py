# TODO

def main():

    text = input("Text: ")
    number_of_letters = count_letters(text)
    number_of_words = count_words(text)
    number_of_sentences = count_sentences(text)


    L = (number_of_letters / number_of_words) * 100
    S = (number_of_sentences / number_of_words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    rounded_index = round(index)

    if rounded_index > 1 and rounded_index <= 16:
        print(f"Grade {rounded_index}")

    if rounded_index > 16:
        print("Grade 16+")

    if rounded_index < 1:
        print("Before Grade 1")


def count_letters(text):
    count = 0
    len_str = len(text)
    for i in range(len_str):
        if text[i] != " " and text[i].isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    len_str = len(text)
    for i in range(len_str):
        if text[i] == " ":
            count += 1

    return count + 1


def count_sentences(text):
    count = 0
    len_str = len(text)
    for i in range(len_str):
        if text[i] == "." or text[i] == "?" or text[i] == "!":
            count += 1

    return count


main()