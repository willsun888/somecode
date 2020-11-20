#[derive(Debug)]
struct Structure(i32);

// Put a `Structure` inside of the structure `Deep`. Make it printable
// also.
#[derive(Debug)]
struct Deep(Structure);

fn main() {
    let _logical: bool = true;
    let an_integer   = 5i32; // Suffix annotation
    println!("{:?} xxx", an_integer);

    println!("1 - 2 = {}", 1u32 - 2);
}
