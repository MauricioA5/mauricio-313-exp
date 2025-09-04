SIZE = 50000
EXPECTED_CHECKSUM = 41667916675000

# Step 1: Initialize Arrays
A = [i for i in range(SIZE)]
B = [SIZE - i for i in range(SIZE)]
# Step 2: Reuse C to store prefix sums of B
C = [0] * SIZE
C[0] = B[0]

for i in range(1, SIZE):
    C[i] = C[i - 1] + B[i]

# Step 3: Compute checksum
checksum = sum(C)

# Step 4: Output the checksum
print(f"Checksum: {checksum}")

# Step 5: Check if checksum matches expected value
if checksum != EXPECTED_CHECKSUM:
    print(f"Error: Checksum mismatch! Expected {EXPECTED_CHECKSUM} but got {checksum}.")
    exit(1)

exit(0)
