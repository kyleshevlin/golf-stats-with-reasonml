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
  course: Courses.course,
  date: string,
  scores: list(score),
};

let scoreFactory = (strokes, fairway, green, putts) => {
  strokes,
  fairway,
  green,
  putts,
};

let round1 = {
  course: Courses.eastmoreland,
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

let round2 = {
  course: Courses.eastmoreland,
  date: "2018-06-24",
  scores: [
    scoreFactory(3, Yes, Yes, 1),
    scoreFactory(4, MissLeft, MissLong, 2),
    scoreFactory(4, Yes, Yes, 2),
    scoreFactory(4, Yes, Yes, 2),
    scoreFactory(2, NoFairway, Yes, 1),
    scoreFactory(5, Yes, Yes, 2),
    scoreFactory(5, MissLeft, MissLeft, 2),
    scoreFactory(2, NoFairway, Yes, 1),
    scoreFactory(5, MissLeft, Yes, 2),
    scoreFactory(5, Yes, MissShort, 1),
    scoreFactory(6, Yes, MissRight, 1),
    scoreFactory(4, NoFairway, Yes, 3),
    scoreFactory(5, Yes, Yes, 3),
    scoreFactory(5, Yes, MissShort, 2),
    scoreFactory(4, Yes, Yes, 2),
    scoreFactory(4, Yes, Yes, 2),
    scoreFactory(3, NoFairway, Yes, 2),
    scoreFactory(5, Yes, Yes, 3)
  ]
};