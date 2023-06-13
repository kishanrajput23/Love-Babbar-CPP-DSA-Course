# Homework

**Q.1 :** Let's assume you are using a switch case statement within an infinite loop and you are restricted from using the `"break"` keyword to exit the loop. How can you exit from that loop?

**Ans :** We can use the `exit` keyword to exit from a loop, including a switch case within an infinite loop. The `exit` keyword is typically used to terminate the entire program, but it can also be used to exit from a loop prematurely.
Here's a general guideline for using exit status values:

- `exit(0)`: This is often used to indicate successful program execution with no errors. It signifies that the program terminated normally and completed its tasks successfully.

- `exit(1)` or any non-zero value: These values are commonly used to indicate that an error or abnormal condition occurred during program execution. The specific value can vary depending on the error or condition encountered. By convention, a non-zero exit status typically signifies some form of failure or error.

**Q.2 :** Why can't we use the continue statement inside the switch case statements?

**Ans :** The reason for this is that the `switch` statement itself is not a loop construct like `for` or `while`. It is used for multi-way branching based on the value of an expression. Each case within the `switch` statement is essentially a label for a specific value, and the control flow transfers to the matching `case` based on the expression's value.

Since the `switch` statement is not a loop, there are no subsequent iterations to skip or continue to. Therefore, the `continue` statement has no meaningful role inside a `switch` statement and is not allowed.

**Q.3 :** Write a program using switch case statement in c++ for calculating the total number of notes required of Rs 100, Rs 50, Rs 20 and Rs 1 for a total number of amount?

