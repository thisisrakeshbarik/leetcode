class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        // Step 1: find users in friendships who cannot communicate
        unordered_set<int> usersNeedingHelp;
        for (auto& friendship : friendships) {
            unordered_map<int, int> langMap;
            bool canCommunicate = false;

            // Mark languages of first friend
            for (int lang : languages[friendship[0] - 1]) {
                langMap[lang] = 1;
            }

            // Check overlap with second friend
            for (int lang : languages[friendship[1] - 1]) {
                if (langMap[lang]) {
                    canCommunicate = true;
                    break;
                }
            }

            // If they cannot talk, add both users
            if (!canCommunicate) {
                usersNeedingHelp.insert(friendship[0] - 1);
                usersNeedingHelp.insert(friendship[1] - 1);
            }
        }

        // Step 2: among usersNeedingHelp, find the language that
        // covers the maximum number of them
        int bestCoverage = 0;
        vector<int> languageCount(n + 1, 0);

        for (int user : usersNeedingHelp) {
            for (int lang : languages[user]) {
                languageCount[lang]++;
                bestCoverage = max(bestCoverage, languageCount[lang]);
            }
        }

        // Step 3: answer = total users needing help - bestCoverage
        return usersNeedingHelp.size() - bestCoverage;
    }
};
