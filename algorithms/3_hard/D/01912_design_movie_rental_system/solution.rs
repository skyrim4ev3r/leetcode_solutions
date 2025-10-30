use std::collections::{HashMap, BTreeSet};
use std::cmp::Ordering;

#[derive(Eq, PartialEq, PartialOrd, Debug, Clone, Hash)]
struct Info {
    shop: i32,
    movie: i32,
    price: i32,
}

impl Ord for Info {
    fn cmp(&self, other: &Self) -> Ordering {
        self.price.cmp(&other.price)
            .then_with(|| self.shop.cmp(&other.shop))
            .then_with(|| self.movie.cmp(&other.movie))
    }
}

struct MovieRentingSystem {
    movie_to_unrented_info: HashMap<i32, BTreeSet<Info>>,
    rented_info: BTreeSet<Info>,
    shop_movie_to_price: HashMap<(i32, i32), i32>
}

impl MovieRentingSystem {

    fn new(n: i32, entries: Vec<Vec<i32>>) -> Self {
        let mut movie_to_unrented_info = HashMap::<i32, BTreeSet<Info>>::new();
        let mut shop_movie_to_price = HashMap::<(i32, i32), i32>::new();
        for entry in entries.into_iter()  {
            movie_to_unrented_info.entry(entry[1]).or_insert(BTreeSet::new())
                .insert(Info {shop: entry[0], movie: entry[1], price: entry[2],});
            shop_movie_to_price.insert((entry[0],  entry[1]), entry[2]);
        }       

        Self {
            movie_to_unrented_info,
            rented_info: BTreeSet::<Info>::new(),
            shop_movie_to_price,
        }
    }
    
    fn search(&self, movie: i32) -> Vec<i32> {
        self.movie_to_unrented_info
            .get(&movie)
            .map_or_else(Vec::new, |shops| shops.iter().map(|info| info.shop).take(5).collect())
    }
    
    fn rent(&mut self, shop: i32, movie: i32) {
        let price = self.shop_movie_to_price[&(shop, movie)];
        let info = Info {shop, price, movie};
        if let Some(val) = self.movie_to_unrented_info.get_mut(&movie) {
                val.remove(&info);
        }
        self.rented_info.insert(info);
    }

    fn drop(&mut self, shop: i32, movie: i32) {
        let price = self.shop_movie_to_price[&(shop, movie)];
        let info = Info {shop, price, movie};
        self.rented_info.remove(&info);
        if let Some(val) = self.movie_to_unrented_info.get_mut(&movie) {
                val.insert(info);
        }
    }

    fn report(&self) -> Vec<Vec<i32>> {
        self.rented_info.iter().take(5).map(|x| vec![x.shop, x.movie]).collect()
    }
}
