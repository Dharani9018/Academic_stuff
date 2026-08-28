import csv

def find_s(data):
    # Step 1: Most specific hypothesis
    h = ["Ø"] * (len(data[0]) - 1) # produces:["Ø", "Ø", "Ø", "Ø", "Ø", "Ø"]

    print("Initial hypothesis:", h)

    # Step 2: Process each training example
    for row in data:

        attributes = row[:-1] #everything except last value
        label = row[-1] # only last values

        print("\nExample:", attributes, "=>", label)

        # Find-S ignores negative examples
        if label.lower() == "no":
            print("Negative example → Ignore")
            continue

        # Process positive example
        for i in range(len(h)):

            # First positive example
            if h[i] == "Ø":
                h[i] = attributes[i] # if the hypothesis is empty, put the example's value into hypothesis.

            # If current hypothesis doesn't match
            elif h[i] != attributes[i]:
                h[i] = "?" # dont care what the attribute is, making the hypothesis more general.

        print("Updated hypothesis:", h)

    return h


# Read CSV
with open("dataset.csv", "r") as file:
    reader = csv.reader(file)

    # Skip header
    next(reader)

    data = list(reader)


# Run Find-S
final_hypothesis = find_s(data)

print("\nFinal Hypothesis:")
print(final_hypothesis)
