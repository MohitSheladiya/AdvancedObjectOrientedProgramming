// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/11/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (unsigned int a = 0; a < desc.size(); a++) {
			for (unsigned int b = 0; b < price.size(); b++) {
				if ((desc[a].code == price[b].code) == true) {
					Product* p = new Product(desc[a].desc, price[b].price);
					p->validate();
					priceList += p;
					delete p;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (unsigned int a = 0; a < desc.size(); a++) {
			for (unsigned int b = 0; b < price.size(); b++) {
				if ((desc[a].code == price[b].code) == true) {
					std::unique_ptr<Product> p(new Product(desc[a].desc, price[b].price));
					p->validate();
					priceList += std::move(p);
				}
			}
		}
		return priceList;
	}
}