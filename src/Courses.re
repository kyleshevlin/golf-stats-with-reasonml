type hole = {
  number: int,
  par: int,
  yards: int,
};

type course = {
  name: string,
  holes: list(hole),
};

let holeFactory = (number, par, yards) : hole => {number, par, yards};

let eastmoreland = {
  name: "Eastmoreland",
  holes: [
    holeFactory(1, 4, 311),
    holeFactory(2, 4, 447),
    holeFactory(3, 4, 337),
    holeFactory(4, 4, 347),
    holeFactory(5, 3, 210),
    holeFactory(6, 5, 497),
    holeFactory(7, 4, 410),
    holeFactory(8, 3, 227),
    holeFactory(9, 5, 497),
    holeFactory(10, 4, 334),
    holeFactory(11, 5, 469),
    holeFactory(12, 3, 167),
    holeFactory(13, 5, 447),
    holeFactory(14, 4, 383),
    holeFactory(15, 4, 381),
    holeFactory(16, 4, 423),
    holeFactory(17, 3, 169),
    holeFactory(18, 4, 457),
  ],
};