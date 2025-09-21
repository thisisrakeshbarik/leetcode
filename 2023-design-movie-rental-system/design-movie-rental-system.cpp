class MovieRentingSystem {
public:

    // search, movie ->price, shops- sorted order 
    // rent , movie, shop ->price remove  move nd shop from other sets, but not from this place to store the price to use in drop case. Add price, shop, movie in reporting set
    // drops,  add movie, shop at last price when rented using stored price, remove from reporting set
    // set storing - price, shope , movie to give report
    unordered_map<int,set<pair<int,int>>>mov_price_shops;
    unordered_map<string,int>shop_movie_price;
    set<vector<int>>price_shop_movie;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
       // n = shops , e = entries
       // o(elogk + e)
        for(auto&it :entries){
            int shop = it[0];
            int movie = it[1];
            int price = it[2];
            //o(logk) k = shops carrying this movie.)
            mov_price_shops[movie].insert({price,shop});
            //o((len(shop)+len(movie)) = O(1)
            string s = to_string(shop)+"_"+to_string(movie);
            shop_movie_price[s] = price;
            

        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        //o(5)
        if(mov_price_shops.find(movie) != mov_price_shops.end()){
            for(auto &it: mov_price_shops[movie]){
                ans.push_back(it.second);
                if(ans.size() == 5){
                    break;
                }
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        // o(log(rented movies) + o(log unrented movies))
        string s = to_string(shop)+"_"+to_string(movie);
        int price = shop_movie_price[s];
        mov_price_shops[movie].erase({price,shop});
        price_shop_movie.insert({price,shop,movie});

    }
    
    void drop(int shop, int movie) {
         // o(log(rented movies) + o(log unrented movies))
        string s = to_string(shop)+"_"+to_string(movie);
        int price = shop_movie_price[s];
        mov_price_shops[movie].insert({price,shop});
        price_shop_movie.erase({price,shop,movie});

    }
    
    vector<vector<int>> report() {
        //O(5)
        vector<vector<int>>ans;
        for(auto &it: price_shop_movie){

            ans.push_back({it[1],it[2]});
            if(ans.size() == 5){
                break;
            }
            
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */