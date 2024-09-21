#[allow(unused)]
use cf::*;

fn main() {}

#[allow(unused)]
mod cf {
    use core::panic;

    pub struct BinaryIndexTree {
        n: usize,
        arr: Vec<i64>, // arr.len() == n + 1
    }

    impl BinaryIndexTree {
        pub fn new(n: usize) -> Self {
            let arr = vec![0; n + 1];
            Self { n, arr }
        }

        pub fn add(&mut self, mut pos: usize, add: i64) {
            while pos <= self.n {
                self.arr[pos] += add;
                pos += Self::lowbit(pos);
            }
        }

        pub fn sum_range(&self, r: std::ops::RangeInclusive<usize>) -> i64 {
            if r.start() < &1 || r.end() > &self.n {
                panic!("bad range");
            }
            self.sum(*r.end()) - self.sum(*r.start() - 1)
        }

        fn sum(&self, mut pos: usize) -> i64 {
            let mut ret = 0;
            while pos > 0 {
                ret += self.arr[pos];
                pos -= Self::lowbit(pos);
            }
            ret
        }

        fn lowbit(x: usize) -> usize {
            let x = x as i64;
            (x & -x) as usize
        }
    }

    #[cfg(test)]
    mod tests {
        use super::*;

        #[test]
        fn basic() {
            let mut bit = BinaryIndexTree::new(100);
            bit.add(11, 2);
            bit.add(13, 5);
            bit.add(100, 233);
            assert_eq!(bit.sum(10), 0);
            assert_eq!(bit.sum(12), 2);
            assert_eq!(bit.sum(14), 7);
            assert_eq!(bit.sum(15), 7);

            assert_eq!(bit.sum_range(1..=100), 240);

            assert_eq!(bit.sum_range(1..=1), 0);
            assert_eq!(bit.sum_range(13..=13), 5);
        }

        #[test]
        #[should_panic]
        fn range_too_low() {
            let bit = BinaryIndexTree::new(100);
            bit.sum_range(0..=100);
        }

        #[test]
        #[should_panic]
        fn range_too_high() {
            let bit = BinaryIndexTree::new(100);
            bit.sum_range(1..=101);
        }
    }

    use std::{
        fmt::{Debug, Display},
        io::{self, BufRead, Read},
        str::FromStr,
    };

    pub fn fast_read_many() -> Vec<usize> {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let mut ret = vec![];
        let mut it = line.chars().into_iter();

        it.fold(0, |accu, x| match x {
            '0'..='9' => accu * 10 + (x as u8 - b'0') as usize,
            _ => {
                ret.push(accu);
                0
            }
        });

        ret
    }

    pub fn read_one<T: FromStr>() -> T
    where
        <T as FromStr>::Err: Debug,
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    }

    pub fn read_3() -> (usize, usize, usize) {
        let mut it = read_many::<usize>().into_iter();
        (it.next().unwrap(), it.next().unwrap(), it.next().unwrap())
    }

    pub fn read_2() -> (usize, usize) {
        let mut it = read_many::<usize>().into_iter();
        (it.next().unwrap(), it.next().unwrap())
    }

    pub fn read_many<T: FromStr>() -> Vec<T>
    where
        <T as FromStr>::Err: Debug,
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        line.split_whitespace()
            .map(|i| i.trim().parse().unwrap())
            .collect()
    }

    pub fn write_many<T: Display>(v: &[T]) {
        for i in v {
            print!("{i} ")
        }
        println!()
    }

    pub fn read_string() -> Vec<char> {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        line.trim().chars().collect()
    }

    pub fn gcd(mut n: usize, mut m: usize) -> usize {
        // assert!(n != 0 && m != 0);
        while m != 0 {
            if m < n {
                std::mem::swap(&mut m, &mut n);
            }
            m %= n;
        }
        n
    }
}
