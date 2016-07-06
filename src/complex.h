#pragma once

struct Complex {
  float re;
  float im;
};

// Addition
struct Complex add(struct Complex first, struct Complex second);

// Subtraction
struct Complex sub(struct Complex minuend, struct Complex subtrahend);

// Multiplication
struct Complex mul(struct Complex first, struct Complex second);

// Division
struct Complex div(struct Complex dividend, struct Complex devider);
