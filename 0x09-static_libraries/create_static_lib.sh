#!/bin/bash

# Compile all .c files in the current directory into object files
gcc -c *.c

# Create a static library called liball.a from the object files
ar -rc liball.a *.o

# Index the static library
ranlib liball.a

# Clean up object files
rm *.o

# Print success message
echo "Static library liball.a created successfully!"

