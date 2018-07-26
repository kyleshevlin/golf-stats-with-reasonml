let total = (nums: list(int)) : int =>
  List.fold_left((sum, cur) => sum + cur, 0, nums);

let totalYards = (course: Courses.course) : int =>
  total(List.map((hole: Courses.hole) => hole.yards, course.holes));

let totalScore = (round: Rounds.round) : int =>
  total(List.map((score: Rounds.score) => score.strokes, round.scores));

let percentFIR = (scores: list(Rounds.score)) : float => {
  let fairways =
    List.filter(
      fairway =>
        switch (fairway) {
        | Rounds.NoFairway => false
        | _ => true
        },
      List.map((score : Rounds.score) => score.fairway, scores),
    );

  let totalFairwaysHit =
    List.fold_left(
      (acc, cur: Rounds.fairwayHit) =>
        switch (cur) {
        | Yes => acc + 1
        | _ => acc
        },
      0,
      List.map((score: Rounds.score) => score.fairway, scores),
    );

  float_of_int(totalFairwaysHit) /. float_of_int(List.length(fairways));
};

let percentGIR = (scores: list(Rounds.score)) : float => {
  let totalGreensHit =
    List.fold_left(
      (acc, cur: Rounds.greenHit) =>
        switch (cur) {
        | Yes => acc + 1
        | _ => acc
        },
      0,
      List.map((score: Rounds.score) => score.green, scores),
    );

  float_of_int(totalGreensHit) /. float_of_int(List.length(scores));
};

let totalPutts = (scores: list(Rounds.score)) : int =>
  total(List.map((score: Rounds.score) => score.putts, scores));

Js.log("Total Score: " ++ string_of_int(totalScore(Rounds.round1)));
Js.log("FIR: " ++ string_of_float(percentFIR(Rounds.round1.scores)));
Js.log("GIR: " ++ string_of_float(percentGIR(Rounds.round1.scores)));
Js.log("Total Putts: " ++ string_of_int(totalPutts(Rounds.round1.scores)));
