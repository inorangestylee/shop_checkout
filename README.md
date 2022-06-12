# Shop checkout emulation

![GitHub](https://img.shields.io/github/license/inorangestylee/shop_checkout)

## Agenda

This is my second attempt at "just for fun" with c++. This programme was implemented, as part of my homework at cpp course.

This program is an emulation of a discounted checkout in a shop and was implemented as part of a cpp course I'm currently taking.
It was written in several approaches for a total of 20+ hours in my spare time.

## Task

The shop has the following:
| product | cost per unit |
| - | - |
| bread | 0.9 |
| white bread | 1.1 |
| milk | 1.3 |
| butter | 3.6 |
| sour cream | 1.8 |
| meat | 16 |
| oranges | 3 |
| apples | 2.5 |
| sugar | 2.05 |
| pasta | 1.29 |

There are also promotions in the shop:

- 33% discount on milks products
- 24% discount on flour products
- 50% discount on a "maximum price in cart" product

You need to write a program that calculates the cost of the shopper's cart taking into account the promotions. Only one promotion can be applied to a product.

The promotion with the maximum value has priority over the others.

### Example

If we have 5 loaves of bread, a packet of butter and two packets of pasta in the basket, the product with the maximum cost is bread
`(5 * 0.9 > 1 * 3.6 > 2 * 1.29)`

Bread falls under two promotions: flour products and the maximum product respectively only the discount on the maximum product from the cart is taken into account.

## Solve

An explanation of how to solve this task with this programm is given in the [solution.md](solution.md)

## Features and what i learned

I played around with this task for a while and made the following

- cli with few commands for user interaction
- classes for shop shelf/client cart, products, promos (dirty, with public accessors, but for now, I'm still learning how to cook them properly)
- met and used `std::tuple` to return multiple values from a function
- used my own namespace `shop`
- played with the `using` directive for individual functions from the standard library
- promos are calculated according to their functions (function ptr)
- interaction with shelf/cart (add/remove product)
- the shelf has a finite number of products
- some products are "whole" and can not be separated (sugar is not whole (kg), bread is whole (loaf))

Known bugs (didn't implement because I got bored):

- shelf and cart sorting (if you take all the goods off the shelf and put them back, print will show this item at the end of the list)
- in many places there are no checks for possible errors and their processing
- to much "gavnokod" (dirty code :))

## Cli commands

```text
command > help

commands:
help - help (this screen)
about - about program and author
quit - exit program

print cart - print client cart content
print shop - print shop shelf content
print promo - print shop promos

add <id> <count> - append product with id <id> and <count> to client's cart
del <id> <count> - remove product with id <id> and <count> from client's cart

checkout - client's cart checkout (with discount)
```

## Questions and topics for further research

- when Promo returned via pointer the name field was empty, after changing the return "by value" the field contained what was expected

## Notes

The programme is not over and will never be over. This is the final raw version which will never be finalised. This project may be of interest to those new to cpp for similar tasks.

**BUT DO NOT USE THIS CODE AS A BEST PRACTICE!**

This written by a beginner in c++!

## Author

Oleg Galushko
