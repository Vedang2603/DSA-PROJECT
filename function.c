#include "function.h"

void recommendFriends(struct User *user, struct SocialNetwork *social_network)
{
    printf("Friend recommendations for %s based on interests:\n", user->username);

    for (int i = 0; i < social_network->num_users; i++)
    {
        if (strcmp(user->username, social_network->users_list[i]->username) == 0)
        {
            continue;
        }

        int commonInterests = 0;
        for (int j = 0; j < user->num_interests; j++)
        {
            for (int k = 0; k < social_network->users_list[i]->num_interests; k++)
            {
                if (strcmp(user->interests[j], social_network->users_list[i]->interests[k]) == 0)
                {
                    commonInterests++;
                    break;
                }
            }
        }

        if (commonInterests > 0)
        {
            printf("- %s (%d common interests)\n", social_network->users_list[i]->username, commonInterests);
        }
    }
}