#![feature(repr128)]

use std::time::Instant;

#[repr(u128)]
fn main() {
    let instant = Instant::now();
    println!("{}", instant.elapsed().as_secs());
    loop {
        let mut prime_numbers: Vec<u64> = Vec::new();
        for index in 1..1000000000 {
            let mut is_prime = true;
            for test in 1..index {
                if ((index - test) % index) != 0 {
                    is_prime = false;
                    break;
                }
            }
            if is_prime {
                prime_numbers.push(index);
            }
        }
        println!("{}", instant.elapsed().as_nanos());
    }
}
