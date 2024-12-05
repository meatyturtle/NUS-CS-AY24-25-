#include <stdio.h>

// function prototype
void func(int);

void func(int a0) {
    int i = 32; // $t0
    int count = 0 + 0; // $v0
    // int a0 = 0; // temp variable

    // jump to L3
    int temp1 = 0; // $t1

    while (1) {
        // slti $t1, $a0, 0
        if (a0 < 0) {
            temp1 = 1;
        } else {
            temp1 = 0;
        }
        // beq $t1, $zero, $L6
        if (temp1 == 0) {
            // go to $L6
            // addi $v0, $v0, 1
            count = count + 1;
            // addi $t0, $t0, ‐1
            i = i + (-1);
        }
        // addi $t0, $t0, ‐1
        i = i + (-1);
        // j $L7
        // beq $t0, $zero, $L8
        if (i == 0) {
            // go to $L8
            // jr $ra - go to address stored in $ra
            break;
        }
        // sll $a0, $a0, 1
        a0 = a0 << 1;
    }

}

int main() {
    func(1);
    return 0;
}
