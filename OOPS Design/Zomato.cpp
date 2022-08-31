#include <bits/stdc++.h>
using namespace std;

class user
{
    string userID;
    string email;
    string phoneNo;
    list<address> addresses;
    list<order> orders;
    list<review> reviews;
    list<restaurant> favourites;
    list<restaurant> visited;
    Cart cart;
};

class restaurant
{
    string restaurantID;
    string name;
    string phoneNo;
    string email;
    string address;
    list<review> reviews;
    list<menu> menu;
    list<order> orders;
    list<user> favourites;
    list<user> visited;
};

class dish
{
    string dishID;
    string name;
    string description;
    string category;
    string cuisine;
    string type;
    string price;
    string discount;
    string rating;
    string image;
    list<review> reviews;
    list<restaurant> favourites;
    list<restaurant> visited;
};

class address
{
    string addressID;
    string address;
    string city;
    string state;
    string pincode;
};

class order
{
    string orderID;
    string orderDate;
    string orderTime;
    string orderStatus;
    string paymentMode;
    string paymentStatus;
    string deliveryAddress;
    string deliveryTime;
    string deliveryDate;
    string deliveryStatus;
    string totalAmount;
    string discount;
    string finalAmount;
    list<dish> dishes;
};

class review
{
    string reviewID;
    string reviewDate;
    string reviewTime;
    string rating;
    string review;
};

class menu
{
    string menuID;
    string menuDate;
    string menuTime;
    list<dish> dishes;
};

class Cart
{
    string cartID;
    string cartDate;
    string cartTime;
    list<dish> dishes;
};
