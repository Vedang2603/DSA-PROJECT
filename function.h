#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Post
{
    // char content[100];
    FILE *fp;
    struct Post *next;
};

// Structure to represent a User
struct User
{
    char username[20];
    char password[20];

    struct User **friends_list; // array of pointers of friends
    int num_friends;
    struct Post *posts_list;
    char **interests;
    int num_interests;

};

// Structure to represent the Social Network
struct SocialNetwork
{
    struct User **users_list;
    int num_users;
};

struct HashMapNode
{
    char username[20];
    char password[20];
    struct HashMapNode *next;
};

struct HashMap
{
    int capacity;
    struct HashMapNode **table;
};


// Function to create a new social network
struct SocialNetwork *createSocialNetwork()
{
    struct SocialNetwork *network = (struct SocialNetwork *)malloc(sizeof(struct SocialNetwork));
    network->users_list = NULL;
    network->num_users = 0;
    return network;
}

//Hashmap functions:-

struct HashMap *createHashMap(int capacity)
{
    struct HashMap *hashMap = (struct HashMap *)malloc(sizeof(struct HashMap));
    hashMap->capacity = capacity;
    hashMap->table = (struct HashMapNode **)malloc(capacity * sizeof(struct HashMapNode *));

    for (int i = 0; i < capacity; i++)
    {
        hashMap->table[i] = NULL;
    }

    return hashMap;
}

void recommendFriends(struct User *user, struct SocialNetwork *social_network);
