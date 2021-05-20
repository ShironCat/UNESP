#[allow(dead_code)]
fn hamming_distance(s1: Vec<char>, s2: Vec<char>) -> u32 {
    let mut dist_counter = 0 as u32;
    for n in 0..s1.len() {
        if s1[n] != s2[n] {
            dist_counter += 1;
        }
    }
    dist_counter
}

#[allow(dead_code, unused_assignments)]
fn levenshtein_distance(s: Vec<char>, t: Vec<char>) -> u32 {
    let n = t.len();
    let mut v0: Vec<u32> = vec![0; n + 1];
    let mut v1: Vec<u32> = vec![0; n + 1];
    for i in 0..n {
        v0[i] = i as u32;
    }
    for i in 0..(s.len() - 1) {
        v1[0] = (i as u32) + 1;
        for j in 0..(n - 1) {
            let deletion_cost = v0[j + 1] + 1;
            let insertion_cost = v1[j] + 1;
            let mut substitution_cost = 0;
            if s[i] == t[j] {
                substitution_cost = v0[j];
            } else {
                substitution_cost = v0[j] + 1;
            }
            v1[j + 1] = std::cmp::min(
                std::cmp::min(deletion_cost, insertion_cost),
                substitution_cost,
            );
        }
        let aux = v0;
        v0 = v1;
        v1 = aux;
    }
    v0[n]
}

#[cfg(test)]
mod tests {
    #[test]
    fn hamming_distance_test() {
        use crate::hamming_distance;
        assert_eq!(2, hamming_distance(vec!['A', 'T'], vec!['T', 'A']));
    }

    #[test]
    fn levenshtein_distance_test() {
        use crate::levenshtein_distance;
        assert_eq!(0, levenshtein_distance(vec!['A', 'T'], vec!['T', 'A']));
    }
}
