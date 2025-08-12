""" 777 """


def augment(gray_codes):
    zero_augmented = []
    one_augmented = []
    for gray_code in gray_codes:
        zero_augmented.append('0' + gray_code)
        one_augmented.append('1' + gray_code)
    one_augmented.reverse()
    augmented_gray_codes = zero_augmented + one_augmented
    return augmented_gray_codes


gray_codes = ['']
for _ in range(int(input())):
    gray_codes = augment(gray_codes)

for gray_code in gray_codes:
    print(gray_code)

# Note: can also be done by considering list of chars instead of string for better memory
