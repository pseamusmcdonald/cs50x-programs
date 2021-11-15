# Credit Card Validation Program

This program implements Luhn’s Algorithm for credit card validation, returning the payment network provider (limited to Visa, Mastercard, & AMEX), and was done along with my self-study of CS50X.

To compile: 

```bash
$ make creditval
```

*This program is meant to be compiled with clang.*

### How to use

Grab a dummy Visa, Mastercard, or AMEX number from [Paypal's developer docs](https://developer.paypal.com/docs/payflow/integration-guide/test-transactions/).

```bash
$ ./creditval
Credit/Debit:371449635398431
AMEX
```