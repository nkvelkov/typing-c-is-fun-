#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

#define MAXN 100

vector<bool> frogs;

vector<string> ans;

bool is_final(int free_place)
{
    int k = frogs.size();
    int n = k / 2;
    if (free_place != n) {
        return false;
    }

    for (int i = 0; i < n; ++i)
    {
        if (frogs[i]) {
            return false;
        }
    }

    for (int i = n+1; i < frogs.size(); ++i)
    {
        if (!frogs[i]) {
            return false;
        }
    }
    return true;
}

std::string FrogsToString(int free_place)
{
    std::string frogs_order;
    for (int i = 0; i < frogs.size(); ++i)
    {
        if (i == free_place)
        {
            frogs_order += '_';
        } else if (frogs[i])
        {
            frogs_order += '>';
        } else
        {
            frogs_order += '<';
        }
    }
    return frogs_order;
}

void print_frogs(int free_place)
{
    for (int i=0; i < frogs.size(); ++i)
    {
        if (i == free_place) {
            printf("_");
        } else if (frogs[i]) {
            printf(">");
        } else {
            printf("<");
        }
    }
}

bool dfs(int free_place)
{
    if (is_final(free_place)) {
        ans.push_back(FrogsToString(free_place));
        return true;
    }

    int old_free_place;

    if (free_place < (int)frogs.size() - 1)
    {
        if(!frogs[free_place+1])
        {
            frogs[free_place] = false;
            old_free_place = free_place;
            free_place++;

            if (dfs(free_place))
            {
                frogs[free_place] = false;
                free_place = old_free_place;
                ans.push_back(FrogsToString(free_place));
                return true;
            }
            frogs[free_place] = false;
            free_place = old_free_place;
        }
    }

    if (free_place < (int)frogs.size() - 2)
    {
        if (!frogs[free_place+2])
        {
            frogs[free_place] = false;
            old_free_place = free_place;
            free_place += 2;

            if (dfs(free_place))
            {
                frogs[free_place] = false;
                free_place = old_free_place;
                ans.push_back(FrogsToString(free_place));
                return true;
            }
            frogs[free_place] = false;
            free_place = old_free_place;
        }
    }

    if (free_place - 1 >= 0)
    {
        if (frogs[free_place-1])
        {
            frogs[free_place] = true;
            old_free_place = free_place;
            free_place--;

            if (dfs(free_place))
            {
                frogs[free_place] = true;
                free_place = old_free_place;
                ans.push_back(FrogsToString(free_place));
                return true;
            }
            frogs[free_place] = true;
            free_place = old_free_place;
        }
    }

    if (free_place - 2 >= 0)
    {
        if (frogs[free_place-2])
        {
            frogs[free_place] = true;
            old_free_place = free_place;
            free_place -= 2;

            if (dfs(free_place))
            {
                frogs[free_place] = true;
                free_place = old_free_place;
                ans.push_back(FrogsToString(free_place));
                return true;
            }
            frogs[free_place] = true;
            free_place = old_free_place;
        }
    }

    return false;
}

int main()
{
    int num_frogs;
    int free_place;

    cin >> num_frogs;

    free_place = num_frogs;

    frogs.reserve(num_frogs*2+10);

    for (int i=0; i < num_frogs; ++i)
    {
        frogs.push_back(true);
    }

    for (int i=num_frogs+1; i <= 2*num_frogs+1; ++i)
    {
        frogs.push_back(false);
    }

    if(dfs(free_place))
    {
        for (int i = (int)ans.size()-1; i >= 0; --i)
        {
            printf("%s\n", ans[i].c_str());
        }
    } else {
        printf("Let's just hope we never get here!");
    }

    return 0;
}
