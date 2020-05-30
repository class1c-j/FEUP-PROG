/*
 * (adapted from Big C++ book) Develop a program to print out an invoice. An invoice describes the charges for a set
 * of products, acquired in certain quantities. Complexities such as dates, taxes, and invoice and costumer numbers may
 * be omitted. The program simply prints the billing  address, all the items (description, unit price, quantity ordered
 * and total price), one item per line, and the total amount due. For simplicity, no user interface is required;
 * simply use a test harness that adds items to the invoice and then prints it.Your program must include the classes:
 * Client(describes the client name and address), Product(describes a product with a description and price),
 * Item(describes a line of the invoice; see example below) and Invoice(describes an invoice for a set of purchased
 * products).
 */

#include "Invoice.h"
#include "Client.h"
#include "Item.h"
#include <vector>

int main() {
    Invoice i(Client("Sonso", Address("Rua dos duendes", "5100-121",
            "Mundo encantado dos brinquedos")), {});
    i.add(Item(Product("sarda", 3.2), 10));
    i.add(Item(Product("nada", 20.01), 1));
    i.show();
    return 0;
}