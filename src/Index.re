type hole = {
  number: int,
  par: int,
  yards: int,
};

type course = {
  name: string,
  holes: list(hole),
};

type fairwayHit =
  | NoFairway
  | Yes
  | MissLeft
  | MissRight;

type greenHit =
  | Yes
  | MissLeftShort
  | MissLeft
  | MissLeftLong
  | MissLong
  | MissRightLong
  | MissRight
  | MissRightShort
  | MissShort;

type goodMiss =
  | Yes
  | No;

type score = {
  strokes: int,
  fairway: fairwayHit,
  green: greenHit,
  putts: int,
};

type round = {
  course,
  date: string,
  scores: list(score),
};

let holeFactory = (number, par, yards) : hole => {number, par, yards};

let scoreFactory = (strokes, fairway, green, putts) => {
  strokes,
  fairway,
  green,
  putts,
};

let totalYards = (course: course) : int =>
  List.fold_left((acc, cur) => acc + cur.yards, 0, course.holes);

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

let totalScore = (round: round) : int =>
  List.fold_left((acc, cur) => acc + cur.strokes, 0, round.scores);

let percentFIR = (scores: list(score)) : float => {
  let fairways =
    List.filter(
      fairway =>
        switch (fairway) {
        | NoFairway => false
        | _ => true
        },
      List.map(score => score.fairway, scores),
    );

  let totalFairwaysHit =
    List.fold_left(
      (acc, cur: fairwayHit) =>
        switch (cur) {
        | Yes => acc + 1
        | _ => acc
        },
      0,
      List.map(score => score.fairway, scores),
    );

  float_of_int(totalFairwaysHit) /. float_of_int(List.length(fairways));
};

let percentGIR = (scores: list(score)) : float => {
  let totalGreensHit =
    List.fold_left(
      (acc, cur: greenHit) =>
        switch (cur) {
        | Yes => acc + 1
        | _ => acc
        },
      0,
      List.map(x => x.green, scores),
    );

  float_of_int(totalGreensHit) /. float_of_int(List.length(scores));
};

let totalPutts = (scores: list(score)) : int =>
  List.fold_left(
    (acc, cur) => acc + cur,
    0,
    List.map(score => score.putts, scores),
  );

let round1 = {
  course: eastmoreland,
  date: "2018-05-27",
  scores: [
    scoreFactory(3, Yes, Yes, 1),
    scoreFactory(5, Yes, MissLeft, 2),
    scoreFactory(4, Yes, Yes, 2),
    scoreFactory(5, Yes, Yes, 3),
    scoreFactory(3, NoFairway, Yes, 2),
    scoreFactory(5, MissRight, Yes, 2),
    scoreFactory(4, Yes, MissShort, 1),
    scoreFactory(4, NoFairway, MissShort, 1),
    scoreFactory(6, MissRight, MissRight, 2),
    scoreFactory(4, Yes, Yes, 2),
    scoreFactory(5, MissLeft, Yes, 2),
    scoreFactory(3, NoFairway, MissLeft, 1),
    scoreFactory(4, MissRight, Yes, 2),
    scoreFactory(4, Yes, MissShort, 1),
    scoreFactory(7, Yes, MissLeft, 1),
    scoreFactory(5, Yes, Yes, 3),
    scoreFactory(5, NoFairway, MissLeftLong, 2),
    scoreFactory(5, MissLeft, MissShort, 2),
  ],
};

Js.log(totalScore(round1));
Js.log(percentFIR(round1.scores));
Js.log(percentGIR(round1.scores));
Js.log(totalPutts(round1.scores));