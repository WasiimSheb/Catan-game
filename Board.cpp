//Wasimshebalny@gmail.com
#include "Board.hpp"
using namespace ariel;

// Constructor for Board class
Board::Board()
{

     // Creating instances of development cards and initializing them
    VictoryPoint *victorypoint = new VictoryPoint();
    YearOfPlenty *yearOfPlenty = new YearOfPlenty();
    Knight *knight = new Knight();
    Monopoly *monopoly = new Monopoly();
    RoadBuilding *roadbuilding = new RoadBuilding();

    // Adding each development card instance and its total count to the 'devCards' map
    cards[victorypoint] = 5;
    cards[yearOfPlenty] = 10;
    cards[knight] = 14;
    cards[monopoly] = 2;
    cards[roadbuilding] = 2;

    // Creating each hexa with specified resource and roll number
    Hexa *h1 = new Hexa(forest, 1, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h2 = new Hexa(pasture, 2, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h3 = new Hexa(fields, 3, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h4 = new Hexa(hills, 4, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h5 = new Hexa(mountains, 5, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h6 = new Hexa(hills, 6, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h7 = new Hexa(pasture, 7, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h8 = new Hexa(desert, 8, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h9 = new Hexa(forest, 9, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h10 = new Hexa(fields, 10, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h11 = new Hexa(forest, 11, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h12 = new Hexa(fields, 12, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h13 = new Hexa(hills, 13, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h14 = new Hexa(pasture, 14, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h15 = new Hexa(pasture, 15, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h16 = new Hexa(mountains, 16, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h17 = new Hexa(mountains, 17, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h18 = new Hexa(fields, 18, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());
    Hexa *h19 = new Hexa(forest, 19, std::vector<City>(), std::vector<Road>(), std::vector<Settlement>());

    /* Setting unique IDs for each hexagons */
    h1->sethex_id(11);
    h2->sethex_id(12);
    h3->sethex_id(9);
    h4->sethex_id(4);
    h5->sethex_id(6);
    h6->sethex_id(5);
    h7->sethex_id(10);
    h8->sethex_id(0);
    h9->sethex_id(3);
    h10->sethex_id(11);
    h11->sethex_id(4);
    h12->sethex_id(8);
    h13->sethex_id(8);
    h14->sethex_id(10);
    h15->sethex_id(9);
    h16->sethex_id(3);
    h17->sethex_id(5);
    h18->sethex_id(2);
    h19->sethex_id(6);

    // Creating nodes with initializations
    Node *v1 = new Node(1, std::vector<Path *>(), std::vector<Hexa *>());   // Node 1 with no initial edges or hexas
    Node *v2 = new Node(2, std::vector<Path *>(), std::vector<Hexa *>());   // Node 2 with no initial edges or hexas
    Node *v3 = new Node(3, std::vector<Path *>(), std::vector<Hexa *>());   // Node 3 with no initial edges or hexas
    Node *v4 = new Node(4, std::vector<Path *>(), std::vector<Hexa *>());   // Node 4 with no initial edges or hexas
    Node *v5 = new Node(5, std::vector<Path *>(), std::vector<Hexa *>());   // Node 5 with no initial edges or hexas
    Node *v6 = new Node(6, std::vector<Path *>(), std::vector<Hexa *>());   // Node 6 with no initial edges or hexas
    Node *v7 = new Node(7, std::vector<Path *>(), std::vector<Hexa *>());   // Node 7 with no initial edges or hexas
    Node *v8 = new Node(8, std::vector<Path *>(), std::vector<Hexa *>());   // Node 8 with no initial edges or hexas
    Node *v9 = new Node(9, std::vector<Path *>(), std::vector<Hexa *>());   // Node 9 with no initial edges or hexas
    Node *v10 = new Node(10, std::vector<Path *>(), std::vector<Hexa *>()); // Node 10 with no initial edges or hexas
    Node *v11 = new Node(11, std::vector<Path *>(), std::vector<Hexa *>()); // Node 11 with no initial edges or hexas
    Node *v12 = new Node(12, std::vector<Path *>(), std::vector<Hexa *>()); // Node 12 with no initial edges or hexas
    Node *v13 = new Node(13, std::vector<Path *>(), std::vector<Hexa *>()); // Node 13 with no initial edges or hexas
    Node *v14 = new Node(14, std::vector<Path *>(), std::vector<Hexa *>()); // Node 14 with no initial edges or hexas
    Node *v15 = new Node(15, std::vector<Path *>(), std::vector<Hexa *>()); // Node 15 with no initial edges or hexas
    Node *v16 = new Node(16, std::vector<Path *>(), std::vector<Hexa *>()); // Node 16 with no initial edges or hexas
    Node *v17 = new Node(17, std::vector<Path *>(), std::vector<Hexa *>()); // Node 17 with no initial edges or hexas
    Node *v18 = new Node(18, std::vector<Path *>(), std::vector<Hexa *>()); // Node 18 with no initial edges or hexas
    Node *v19 = new Node(19, std::vector<Path *>(), std::vector<Hexa *>()); // Node 19 with no initial edges or hexas
    Node *v20 = new Node(20, std::vector<Path *>(), std::vector<Hexa *>()); // Node 20 with no initial edges or hexas
    Node *v21 = new Node(21, std::vector<Path *>(), std::vector<Hexa *>()); // Node 21 with no initial edges or hexas
    Node *v22 = new Node(22, std::vector<Path *>(), std::vector<Hexa *>()); // Node 22 with no initial edges or hexas
    Node *v23 = new Node(23, std::vector<Path *>(), std::vector<Hexa *>()); // Node 23 with no initial edges or hexas
    Node *v24 = new Node(24, std::vector<Path *>(), std::vector<Hexa *>()); // Node 24 with no initial edges or hexas
    Node *v25 = new Node(25, std::vector<Path *>(), std::vector<Hexa *>()); // Node 25 with no initial edges or hexas
    Node *v26 = new Node(26, std::vector<Path *>(), std::vector<Hexa *>()); // Node 26 with no initial edges or hexas
    Node *v27 = new Node(27, std::vector<Path *>(), std::vector<Hexa *>()); // Node 27 with no initial edges or hexas
    Node *v28 = new Node(28, std::vector<Path *>(), std::vector<Hexa *>()); // Node 28 with no initial edges or hexas
    Node *v29 = new Node(29, std::vector<Path *>(), std::vector<Hexa *>()); // Node 29 with no initial edges or hexas
    Node *v30 = new Node(30, std::vector<Path *>(), std::vector<Hexa *>()); // Node 30 with no initial edges or hexas
    Node *v31 = new Node(31, std::vector<Path *>(), std::vector<Hexa *>()); // Node 31 with no initial edges or hexas
    Node *v32 = new Node(32, std::vector<Path *>(), std::vector<Hexa *>()); // Node 32 with no initial edges or hexas
    Node *v33 = new Node(33, std::vector<Path *>(), std::vector<Hexa *>()); // Node 33 with no initial edges or hexas
    Node *v34 = new Node(34, std::vector<Path *>(), std::vector<Hexa *>()); // Node 34 with no initial edges or hexas
    Node *v35 = new Node(35, std::vector<Path *>(), std::vector<Hexa *>()); // Node 35 with no initial edges or hexas
    Node *v36 = new Node(36, std::vector<Path *>(), std::vector<Hexa *>()); // Node 36 with no initial edges or hexas
    Node *v37 = new Node(37, std::vector<Path *>(), std::vector<Hexa *>()); // Node 37 with no initial edges or hexas
    Node *v38 = new Node(38, std::vector<Path *>(), std::vector<Hexa *>()); // Node 38 with no initial edges or hexas
    Node *v39 = new Node(39, std::vector<Path *>(), std::vector<Hexa *>()); // Node 39 with no initial edges or hexas
    Node *v40 = new Node(40, std::vector<Path *>(), std::vector<Hexa *>()); // Node 40 with no initial edges or hexas
    Node *v41 = new Node(41, std::vector<Path *>(), std::vector<Hexa *>()); // Node 41 with no initial edges or hexas
    Node *v42 = new Node(42, std::vector<Path *>(), std::vector<Hexa *>()); // Node 42 with no initial edges or hexas
    Node *v43 = new Node(43, std::vector<Path *>(), std::vector<Hexa *>()); // Node 43 with no initial edges or hexas
    Node *v44 = new Node(44, std::vector<Path *>(), std::vector<Hexa *>()); // Node 44 with no initial edges or hexas
    Node *v45 = new Node(45, std::vector<Path *>(), std::vector<Hexa *>()); // Node 45 with no initial edges or hexas
    Node *v46 = new Node(46, std::vector<Path *>(), std::vector<Hexa *>()); // Node 46 with no initial edges or hexas
    Node *v47 = new Node(47, std::vector<Path *>(), std::vector<Hexa *>()); // Node 47 with no initial edges or hexas
    Node *v48 = new Node(48, std::vector<Path *>(), std::vector<Hexa *>()); // Node 48 with no initial edges or hexas
    Node *v49 = new Node(49, std::vector<Path *>(), std::vector<Hexa *>()); // Node 49 with no initial edges or hexas
    Node *v50 = new Node(50, std::vector<Path *>(), std::vector<Hexa *>()); // Node 50 with no initial edges or hexas
    Node *v51 = new Node(51, std::vector<Path *>(), std::vector<Hexa *>()); // Node 51 with no initial edges or hexas
    Node *v52 = new Node(52, std::vector<Path *>(), std::vector<Hexa *>()); // Node 52 with no initial edges or hexas
    Node *v53 = new Node(53, std::vector<Path *>(), std::vector<Hexa *>()); // Node 53 with no initial edges or hexas
    Node *v54 = new Node(54, std::vector<Path *>(), std::vector<Hexa *>()); // Node 54 with no initial edges or hexas

    // Creating paths between nodes
    Path *path1 = new Path(1, v1, v14);    // path 1 connecting Node 1 to Node 14
    Path *path2 = new Path(2, v1, v2);     // path 2 connecting Node 1 to Node 2
    Path *path3 = new Path(3, v2, v3);     // path 3 connecting Node 2 to Node 3
    Path *path4 = new Path(4, v3, v4);     // path 4 connecting Node 3 to Node 4
    Path *path5 = new Path(5, v4, v5);     // path 5 connecting Node 4 to Node 5
    Path *path6 = new Path(6, v5, v6);     // path 6 connecting Node 5 to Node 6
    Path *path7 = new Path(7, v6, v7);     // path 7 connecting Node 6 to Node 7
    Path *path8 = new Path(8, v7, v8);     // path 8 connecting Node 7 to Node 8
    Path *path9 = new Path(9, v8, v9);     // path 9 connecting Node 8 to Node 9
    Path *path10 = new Path(10, v9, v10);  // path 10 connecting Node 9 to Node 10
    Path *path11 = new Path(11, v10, v5);  // path 11 connecting Node 10 to Node 5
    Path *path12 = new Path(12, v10, v11); // path 12 connecting Node 10 to Node 11
    Path *path13 = new Path(13, v11, v12); // path 13 connecting Node 11 to Node 12
    Path *path14 = new Path(14, v12, v3);  // path 14 connecting Node 12 to Node 3
    Path *path15 = new Path(15, v12, v13); // path 15 connecting Node 12 to Node 13
    Path *path16 = new Path(16, v13, v14); // path 16 connecting Node 13 to Node 14
    Path *path17 = new Path(17, v14, v15); // path 17 connecting Node 14 to Node 15
    Path *path18 = new Path(18, v16, v16); // path 18 (self-loop) at Node 16
    Path *path19 = new Path(19, v16, v17); // path 19 connecting Node 16 to Node 17
    Path *path20 = new Path(20, v17, v18); // path 20 connecting Node 17 to Node 18
    Path *path21 = new Path(21, v18, v13); // path 21 connecting Node 18 to Node 13
    Path *path22 = new Path(22, v18, v19); // path 22 connecting Node 18 to Node 19
    Path *path23 = new Path(23, v19, v20); // path 23 connecting Node 19 to Node 20
    Path *path24 = new Path(24, v20, v11); // path 24 connecting Node 20 to Node 11
    Path *path25 = new Path(25, v20, v21); // path 25 connecting Node 20 to Node 21
    Path *path26 = new Path(26, v21, v22); // path 26 connecting Node 21 to Node 22
    Path *path27 = new Path(27, v22, v9);  // path 27 connecting Node 22 to Node 9
    Path *path28 = new Path(28, v22, v23); // path 28 connecting Node 22 to Node 23
    Path *path29 = new Path(29, v23, v25); // path 29 connecting Node 23 to Node 25
    Path *path30 = new Path(30, v25, v24); // path 30 connecting Node 25 to Node 24
    Path *path31 = new Path(31, v24, v8);  // path 31 connecting Node 24 to Node 8
    Path *path32 = new Path(32, v25, v26); // path 32 connecting Node 25 to Node 26
    Path *path33 = new Path(33, v26, v27); // path 33 connecting Node 26 to Node 27
    Path *path34 = new Path(34, v27, v28); // path 34 connecting Node 27 to Node 28
    Path *path35 = new Path(35, v28, v29); // path 35 connecting Node 28 to Node 29
    Path *path36 = new Path(36, v29, v23); // path 36 connecting Node 29 to Node 23
    Path *path37 = new Path(37, v29, v30); // path 37 connecting Node 29 to Node 30
    Path *path38 = new Path(38, v30, v31); // path 38 connecting Node 30 to Node 31
    Path *path39 = new Path(39, v31, v32); // path 39 connecting Node 31 to Node 32
    Path *path40 = new Path(40, v31, v32); // path 40 connecting Node 31 to Node 32
    Path *path41 = new Path(41, v32, v33); // path 41 connecting Node 32 to Node 33
    Path *path42 = new Path(42, v33, v19); // path 42 connecting Node 33 to Node 19
    Path *path43 = new Path(43, v33, v34); // path 43 connecting Node 33 to Node 34
    Path *path44 = new Path(44, v34, v35); // path 44 connecting Node 34 to Node 35
    Path *path45 = new Path(45, v35, v17); // path 45 connecting Node 35 to Node 17
    Path *path46 = new Path(46, v35, v36); // path 46 connecting Node 35 to Node 36
    Path *path47 = new Path(47, v36, v38); // path 47 connecting Node 36 to Node 38
    Path *path48 = new Path(48, v38, v37); // path 48 connecting Node 38 to Node 37
    Path *path49 = new Path(49, v37, v16); // path 49 connecting Node 37 to Node 16
    Path *path50 = new Path(50, v36, v39); // path 50 connecting Node 36 to Node 39
    Path *path51 = new Path(51, v39, v40); // path 51 connecting Node 39 to Node 40
    Path *path52 = new Path(52, v40, v41); // path 52 connecting Node 40 to Node 41
    Path *path53 = new Path(53, v41, v34); // path 53 connecting Node 41 to Node 34
    Path *path54 = new Path(54, v41, v42); // path 54 connecting Node 41 to Node 42
    Path *path55 = new Path(55, v42, v43); // path 55 connecting Node 42 to Node 43
    Path *path56 = new Path(56, v43, v32); // path 56 connecting Node 43 to Node 32
    Path *path57 = new Path(57, v43, v44); // path 57 connecting Node 43 to Node 44
    Path *path58 = new Path(58, v44, v45); // path 58 connecting Node 44 to Node 45
    Path *path59 = new Path(59, v45, v30); // path 59 connecting Node 45 to Node 30
    Path *path60 = new Path(60, v45, v46); // path 60 connecting Node 45 to Node 46
    Path *path61 = new Path(61, v46, v47); // path 61 connecting Node 46 to Node 47
    Path *path62 = new Path(62, v47, v28); // path 62 connecting Node 47 to Node 28
    Path *path63 = new Path(63, v46, v48); // path 63 connecting Node 46 to Node 48
    Path *path64 = new Path(64, v48, v49); // path 64 connecting Node 48 to Node 49
    Path *path65 = new Path(65, v49, v50); // path 65 connecting Node 49 to Node 50
    Path *path66 = new Path(66, v50, v44); // path 66 connecting Node 50 to Node 44
    Path *path67 = new Path(67, v50, v51); // path 67 connecting Node 50 to Node 51
    Path *path68 = new Path(68, v51, v52); // path 68 connecting Node 51 to Node 52
    Path *path69 = new Path(69, v52, v42); // path 69 connecting Node 52 to Node 42
    Path *path70 = new Path(70, v52, v53); // path 70 connecting Node 52 to Node 53
    Path *path71 = new Path(71, v53, v54); // path 69 connecting Node 53 to Node 54
    Path *path72 = new Path(72, v54, v40); // path 69 connecting Node 54 to Node 40
                                                                          
    // Define nodes v1 to v53 and associated edges path1 to e72 and hexas h1 to h19

    // Node v1
    v1->addPath(path1);  // Connect v1 to v2 via path3 path1
    v1->addPath(path2);  // Connect v1 to v2 via path3 path2
    v1->addHexa(h1); // Assign hexa h1 to v1

    // Node v2
    v2->addPath(path2);  // Connect v2 to v3 via path3 path2
    v2->addPath(path3);  // Connect v2 to v3 via path3 path3
    v2->addHexa(h1); // Assign hexa h1 to v2

    // Node v3
    v3->addPath(path3);  // Connect v3 to v4 via path3 path3
    v3->addPath(path4);  // Connect v3 to v4 via path3 path4
    v3->addHexa(h1); // Assign hexa h1 to v3
    v3->addHexa(h2); // Assign hexa tt2 to v3

    // Node v4
    v4->addPath(path4);  // Connect v4 to v5 via path3 path4
    v4->addPath(path5);  // Connect v4 to v5 via path3 path5
    v4->addHexa(h2); // Assign hexa tt2 to v4

    // Node v5
    v5->addPath(path5);  // Connect v5 to v6 via path3 path5
    v5->addPath(path6);  // Connect v5 to v6 via path3 path6
    v5->addHexa(h2); // Assign hexa tt2 to v5
    v5->addHexa(h3); // Assign hexa tt3 to v5

    // Node v6
    v6->addPath(path6);  // Connect v6 to v7 via path3 path6
    v6->addPath(path7);  // Connect v6 to v7 via path3 path7
    v6->addHexa(h3); // Assign hexa tt3 to v6

    // Node v7
    v7->addPath(path7);  // Connect v7 to v8 via path3 path7
    v7->addPath(path8);  // Connect v7 to v8 via path3 path8
    v7->addHexa(h3); // Assign hexa tt3 to v7

    // Node v8
    v8->addPath(path8);  // Connect v8 to v9 via path3 path8
    v8->addPath(path9);  // Connect v8 to v9 via path3 path9
    v8->addPath(path31); // Connect v8 to v24 via path3 path31
    v8->addHexa(h3); // Assign hexa tt3 to v8
    v8->addHexa(h7); // Assign hexa h7 to v8

    // Node v9
    v9->addPath(path9);  // Connect v9 to v10 via path3 path9
    v9->addPath(path10); // Connect v9 to v10 via path3 path10
    v9->addPath(path27); // Connect v9 to v22 via path3 path27
    v9->addHexa(h3); // Assign hexa tt3 to v9
    v9->addHexa(h7); // Assign hexa h7 to v9
    v9->addHexa(h6); // Assign hexa tt6 to v9

    // Node v10
    v10->addPath(path11); // Connect v10 to v9 via path3 path11
    v10->addPath(path10); // Connect v10 to v9 via path3 path10
    v10->addPath(path12); // Connect v10 to v11 via path3 path12
    v10->addHexa(h2); // Assign hexa tt2 to v10
    v10->addHexa(h3); // Assign hexa tt3 to v10
    v10->addHexa(h6); // Assign hexa tt6 to v10

    // Node v11
    v11->addPath(path12); // Connect v11 to v10 via path3 path12
    v11->addPath(path13); // Connect v11 to v12 via path3 path13
    v11->addPath(path24); // Connect v11 to v20 via path3 path24
    v11->addHexa(h2); // Assign hexa tt2 to v11
    v11->addHexa(h5); // Assign hexa h5 to v11
    v11->addHexa(h6); // Assign hexa tt6 to v11

    // Node v12
    v12->addPath(path13); // Connect v12 to v11 via path3 path13
    v12->addPath(path14); // Connect v12 to v13 via path3 path14
    v12->addPath(path15); // Connect v12 to v13 via path3 path15
    v12->addHexa(h1); // Assign hexa h1 to v12
    v12->addHexa(h2); // Assign hexa tt2 to v12
    v12->addHexa(h5); // Assign hexa h5 to v12

    // Node v13
    v13->addPath(path15); // Connect v13 to v12 via path3 path15
    v13->addPath(path16); // Connect v13 to v14 via path3 path16
    v13->addPath(path21); // Connect v13 to v19 via path3 path21
    v13->addHexa(h1); // Assign hexa h1 to v13
    v13->addHexa(h4); // Assign hexa tt4 to v13
    v13->addHexa(h5); // Assign hexa h5 to v13

    // Node v14
    v14->addPath(path1);  // Connect v14 to v1 via path3 path1
    v14->addPath(path16); // Connect v14 to v15 via path3 path16
    v14->addPath(path17); // Connect v14 to v15 via path3 path17
    v14->addHexa(h1); // Assign hexa h1 to v14
    v14->addHexa(h4); // Assign hexa tt4 to v14

    // Node v15
    v15->addPath(path17); // Connect v15 to v16 via path3 path17
    v15->addPath(path18); // Connect v15 to v16 via path3 path18
    v15->addHexa(h4); // Assign hexa tt4 to v15

    // Node v16
    v16->addPath(path18); // Connect v16 to v17 via path3 path18
    v16->addPath(path19); // Connect v16 to v17 via path3 path19
    v16->addPath(path49); // Connect v16 to v50 via path3 e49
    v16->addHexa(h4); // Assign hexa tt4 to v16
    v16->addHexa(h8); // Assign hexa h8 to v16

    // Node v17
    v17->addPath(path20); // Connect v17 to v18 via path3 path20
    v17->addPath(path19); // Connect v17 to v18 via path3 path19
    v17->addPath(path45); // Connect v17 to v46 via path3 e45
    v17->addHexa(h4); // Assign hexa tt4 to v17
    v17->addHexa(h8); // Assign hexa h8 to v17
    v17->addHexa(h9); // Assign hexa h9 to v17

    // Node v18
    v18->addPath(path20); // Connect v18 to v17 via path3 path20
    v18->addPath(path21); // Connect v18 to v19 via path3 path21
    v18->addPath(path22); // Connect v18 to v19 via path3 path22
    v18->addHexa(h4); // Assign hexa tt4 to v18
    v18->addHexa(h5); // Assign hexa h5 to v18
    v18->addHexa(h9); // Assign hexa h9 to v18

    // Node v19
    v19->addPath(path22);  // Connect v19 to v18 via path3 path22
    v19->addPath(path23);  // Connect v19 to v20 via path3 path23
    v19->addPath(path42);  // Connect v19 to v43 via path3 e42
    v19->addHexa(h5);  // Assign hexa h5 to v19
    v19->addHexa(h10); // Assign hexa h10 to v19
    v19->addHexa(h9);  // Assign hexa h9 to v19

    // Node v20
    v20->addPath(path24);  // Connect v20 to v23 via path3 path24
    v20->addPath(path23);  // Connect v20 to v23 via path3 path23
    v20->addPath(path25);  // Connect v20 to v21 via path3 path25
    v20->addHexa(h5);  // Assign hexa h5 to v20
    v20->addHexa(h6);  // Assign hexa h6 to v20
    v20->addHexa(h10); // Assign hexa h10 to v20

    // Node v21
    v21->addPath(path25);  // Connect v21 to v20 via path3 path25
    v21->addPath(path26);  // Connect v21 to v22 via path3 path26
    v21->addPath(path39);  // Connect v21 to v40 via path3 path39
    v21->addHexa(h6);  // Assign hexa tt6 to v21
    v21->addHexa(h10); // Assign hexa h10 to v21
    v21->addHexa(h11); // Assign hexa h11 to v21

    // Node v22
    v22->addPath(path27);  // Connect v22 to v23 via path3 path27
    v22->addPath(path28);  // Connect v22 to v23 via path3 path28
    v22->addPath(path26);  // Connect v22 to v21 via path3 path26
    v22->addHexa(h6);  // Assign hexa tt6 to v22
    v22->addHexa(h7);  // Assign hexa h7 to v22
    v22->addHexa(h11); // Assign hexa h11 to v22

    // Node v23
    v23->addPath(path28);  // Connect v23 to v22 via path3 path28
    v23->addPath(path29);  // Connect v23 to v24 via path3 path29
    v23->addPath(path36);  // Connect v23 to v37 via path3 path36
    v23->addHexa(h7);  // Assign hexa h7 to v23
    v23->addHexa(h11); // Assign hexa h11 to v23
    v23->addHexa(h12); // Assign hexa h12 to v23

    // Node v24
    v24->addPath(path31); // Connect v24 to v32 via path3 path31
    v24->addPath(path30); // Connect v24 to v25 via path3 path30
    v24->addHexa(h7); // Assign hexa h7 to v24

    // Node v25
    v25->addPath(path29);  // Connect v25 to v24 via path3 path29
    v25->addPath(path30);  // Connect v25 to v24 via path3 path30
    v25->addPath(path32);  // Connect v25 to v26 via path3 path32
    v25->addHexa(h7);  // Assign hexa h7 to v25
    v25->addHexa(h12); // Assign hexa h12 to v25

    // Node v26
    v26->addPath(path33);  // Connect v26 to v27 via path3 path33
    v26->addPath(path32);  // Connect v26 to v27 via path3 path32
    v26->addHexa(h12); // Assign hexa h12 to v26

    // Node v27
    v27->addPath(path33);  // Connect v27 to v28 via path3 path33
    v27->addPath(path34);  // Connect v27 to v28 via path3 e34
    v27->addHexa(h12); // Assign hexa h12 to v27

    // Node v28
    v28->addPath(path34);  // Connect v28 to v29 via path3 e34
    v28->addPath(path35);  // Connect v28 to v29 via path3 path35
    v28->addPath(path62);  // Connect v28 to v63 via path3 e62
    v28->addHexa(h6);  // Assign hexa tt6 to v28
    v28->addHexa(h12); // Assign hexa h12 to v28

    // Node v29
    v29->addPath(path35);  // Connect v29 to v30 via path3 path35
    v29->addPath(path36);  // Connect v29 to v30 via path3 path36
    v29->addPath(path37);  // Connect v29 to v38 via path3 path37
    v29->addHexa(h1);  // Assign hexa h1 to v29
    v29->addHexa(h12); // Assign hexa h12 to v29
    v29->addHexa(h16); // Assign hexa h16 to v29

    // Node v30
    v30->addPath(path37);  // Connect v30 to v31 via path3 path37
    v30->addPath(path38);  // Connect v30 to v31 via path3 path38
    v30->addPath(path59);  // Connect v30 to v60 via path3 e59
    v30->addHexa(h11); // Assign hexa h11 to v30
    v30->addHexa(h15); // Assign hexa 15 to v30
    v30->addHexa(h16); // Assign hexa h16 to v30

    // Node v31
    v31->addPath(path40);  // Connect v31 to v32 via path3 path40
    v31->addPath(path38);  // Connect v31 to v32 via path3 path38
    v31->addPath(path39);  // Connect v31 to v40 via path3 path39
    v31->addHexa(h10); // Assign hexa h10 to v31
    v31->addHexa(h15); // Assign hexa 15 to v31
    v31->addHexa(h11); // Assign hexa h11 to v31

    // Node v32
    v32->addPath(path40);  // Connect v32 to v33 via path3 path40
    v32->addPath(path41);  // Connect v32 to v33 via path3 e41
    v32->addPath(path56);  // Connect v32 to v57 via path3 e56
    v32->addHexa(h10); // Assign hexa h10 to v32
    v32->addHexa(h15); // Assign hexa 15 to v32
    v32->addHexa(h14); // Assign hexa h14 to v32

    // Node v33
    v33->addPath(path41);  // Connect v33 to v34 via path3 e41
    v33->addPath(path42);  // Connect v33 to v34 via path3 e42
    v33->addPath(path43);  // Connect v33 to v44 via path3 e43
    v33->addHexa(h10); // Assign hexa h10 to v33
    v33->addHexa(h9);  // Assign hexa h9 to v33
    v33->addHexa(h14); // Assign hexa h14 to v33

    // Node v34
    v34->addPath(path43);  // Connect v34 to v35 via path3 e43
    v34->addPath(path44);  // Connect v34 to v35 via path3 e44
    v34->addPath(path53);  // Connect v34 to v54 via path3 e53
    v34->addHexa(h9);  // Assign hexa h9 to v34
    v34->addHexa(h13); // Assign hexa h13 to v34
    v34->addHexa(h14); // Assign hexa h14 to v34

    // Node v35
    v35->addPath(path44);  // Connect v35 to v36 via path3 e44
    v35->addPath(path45);  // Connect v35 to v36 via path3 e45
    v35->addPath(path46);  // Connect v35 to v47 via path3 e46
    v35->addHexa(h8);  // Assign hexa h8 to v35
    v35->addHexa(h9);  // Assign hexa h9 to v35
    v35->addHexa(h13); // Assign hexa h13 to v35

    // Node v36
    v36->addPath(path46);  // Connect v36 to v37 via path3 e46
    v36->addPath(path47);  // Connect v36 to v38 via path3 e47
    v36->addPath(path50);  // Connect v36 to v51 via path3 e50
    v36->addHexa(h8);  // Assign hexa h8 to v36
    v36->addHexa(h13); // Assign hexa h13 to v36

    // Node v37
    v37->addPath(path49); // Connect v37 to v50 via path3 e49
    v37->addPath(path48); // Connect v37 to v38 via path3 e48
    v37->addHexa(h8); // Assign hexa h8 to v37

    // Node v38
    v38->addPath(path47); // Connect v38 to v48 via path3 e47
    v38->addPath(path48); // Connect v38 to v48 via path3 e48
    v38->addHexa(h8); // Assign hexa h8 to v38

    // Node v39
    v39->addPath(path50);  // Connect v39 to v51 via path3 e50
    v39->addPath(path51);  // Connect v39 to v52 via path3 e51
    v39->addHexa(h13); // Assign hexa h13 to v39

    // Node v40
    v40->addPath(path51);  // Connect v40 to v52 via path3 e51
    v40->addPath(path52);  // Connect v40 to v53 via path3 e52
    v40->addPath(path72);  // Connect v40 to v73 via path3 e72
    v40->addHexa(h13); // Assign hexa h13 to v40
    v40->addHexa(h17); // Assign hexa h17 to v40

    // Node v41
    v41->addPath(path52);  // Connect v41 to v53 via path3 e52
    v41->addPath(path53);  // Connect v41 to v54 via path3 e53
    v41->addPath(path54);  // Connect v41 to v55 via path3 e54
    v41->addHexa(h13); // Assign hexa h13 to v41
    v41->addHexa(h14); // Assign hexa h14 to v41
    v41->addHexa(h17); // Assign hexa h17 to v41

    // Node v42
    v42->addPath(path54);  // Connect v42 to v55 via path3 e54
    v42->addPath(path55);  // Connect v42 to v56 via path3 e55
    v42->addPath(path69);  // Connect v42 to v70 via path3 e69
    v42->addHexa(h18); // Assign hexa h18 to v42
    v42->addHexa(h14); // Assign hexa h14 to v42
    v42->addHexa(h17); // Assign hexa h17 to v42

    // Node v43
    v43->addPath(path55);  // Connect v43 to v56 via path3 e55
    v43->addPath(path56);  // Connect v43 to v57 via path3 e56
    v43->addPath(path57);  // Connect v43 to v58 via path3 e57
    v43->addHexa(h18); // Assign hexa h18 to v43
    v43->addHexa(h14); // Assign hexa h14 to v43
    v43->addHexa(h15); // Assign hexa 15 to v43

    // Node v44
    v44->addPath(path57);  // Connect v44 to v58 via path3 e57
    v44->addPath(path58);  // Connect v44 to v59 via path3 e58
    v44->addPath(path66);  // Connect v44 to v67 via path3 e66
    v44->addHexa(h18); // Assign hexa h18 to v44
    v44->addHexa(h19); // Assign hexa h19 to v44
    v44->addHexa(h15); // Assign hexa 15 to v44

    // Node v45
    v45->addPath(path58);  // Connect v45 to v59 via path3 e58
    v45->addPath(path59);  // Connect v45 to v60 via path3 e59
    v45->addPath(path60);  // Connect v45 to v61 via path3 e60
    v45->addHexa(h16); // Assign hexa h16 to v45
    v45->addHexa(h19); // Assign hexa h19 to v45
    v45->addHexa(h15); // Assign hexa 15 to v45

    // Node v46
    v46->addPath(path60);  // Connect v46 to v61 via path3 e60
    v46->addPath(path61);  // Connect v46 to v62 via path3 e61
    v46->addPath(path63);  // Connect v46 to v64 via path3 e63
    v46->addHexa(h16); // Assign hexa h16 to v46
    v46->addHexa(h19); // Assign hexa h19 to v46

    // Node v47
    v47->addPath(path62);  // Connect v47 to v63 via path3 e62
    v47->addPath(path61);  // Connect v47 to v62 via path3 e61
    v47->addHexa(h16); // Assign hexa h16 to v47

    // Node v48
    v48->addPath(path64);  // Connect v48 to v65 via path3 e64
    v48->addPath(path63);  // Connect v48 to v64 via path3 e63
    v48->addHexa(h19); // Assign hexa h19 to v48

    // Node v49
    v49->addPath(path64);  // Connect v49 to v65 via path3 e64
    v49->addPath(path65);  // Connect v49 to v66 via path3 e65
    v49->addHexa(h19); // Assign hexa h19 to v49

    // Node v50
    v50->addPath(path65);  // Connect v50 to v66 via path3 e65
    v50->addPath(path66);  // Connect v50 to v67 via path3 e66
    v50->addPath(path67);  // Connect v50 to v68 via path3 e67
    v50->addHexa(h19); // Assign hexa h19 to v50
    v50->addHexa(h18); // Assign hexa h18 to v50

    // Node v514
    v51->addPath(path67);  // 4Connect v51 to v68 via path3 e67
    v51->addPath(path68);  // Connect v51 to v69 via path3 e68
    v51->addHexa(h18); // Assign hexa h18 to v51

    // Node v52
    v52->addPath(path68);  // Connect v52 to v69 via path3 e68
    v52->addPath(path69);  // Connect v52 to v70 via path3 e69
    v52->addPath(path70);  // Connect v52 to v71 via path3 e70
    v52->addHexa(h17); // Assign hexa h17 to v52
    v52->addHexa(h18); // Assign hexa h18 to v52

    // Node v53
    v53->addPath(path70);  // Connect v53 to v71 via path3 e70
    v53->addPath(path71);  // Connect v53 to v72 via path3 e71
    v53->addHexa(h17); // Assign hexa h17 to v53

    /* Node pointers to representing the Hexas */
    std::vector<Node *> hexa1 = {v1, v2, v3, v12, v13, v14};
    std::vector<Node *> hexa2 = {v3, v4, v5, v12, v11, v10};
    std::vector<Node *> hexa3 = {v5, v6, v7, v8, v9, v10};
    std::vector<Node *> hexa4 = {v13, v14, v15, v16, v17, v18};
    std::vector<Node *> hexa5 = {v11, v12, v13, v18, v19, v20};
    std::vector<Node *> hexa6 = {v9, v10, v11, v20, v21, v22};
    std::vector<Node *> hexa7 = {v8, v9, v3, v22, v23, v25};
    std::vector<Node *> hexa8 = {v16, v17, v35, v36, v38, v37};
    std::vector<Node *> hexa9 = {v17, v18, v19, v33, v34, v35};
    std::vector<Node *> hexa10 = {v19, v20, v21, v31, v32, v33};
    std::vector<Node *> hexa11 = {v21, v22, v23, v29, v30, v31};
    std::vector<Node *> hexa12 = {v23, v25, v26, v27, v28, v29};
    std::vector<Node *> hexa13 = {v34, v35, v36, v39, v40, v41};
    std::vector<Node *> hexa14 = {v32, v33, v34, v41, v42, v43};
    std::vector<Node *> hexa15 = {v30, v31, v32, v43, v44, v45};
    std::vector<Node *> hexa16 = {v28, v29, v30, v45, v46, v47};
    std::vector<Node *> hexa17 = {v40, v41, v42, v52, v53, v54};
    std::vector<Node *> hexa18 = {v42, v43, v44, v50, v51, v52};
    std::vector<Node *> hexa19 = {v44, v45, v46, v48, v49, v50};

    /* Setting nodes for each Hexa object */
    h1->setNode(hexa1);
    h2->setNode(hexa2);
    h3->setNode(hexa3);
    h4->setNode(hexa4);
    h5->setNode(hexa5);
    h6->setNode(hexa6);
    h7->setNode(hexa7);
    h8->setNode(hexa8);
    h9->setNode(hexa9);
    h10->setNode(hexa10);
    h11->setNode(hexa11);
    h12->setNode(hexa12);
    h13->setNode(hexa13);
    h14->setNode(hexa14);
    h15->setNode(hexa15);
    h16->setNode(hexa16);
    h17->setNode(hexa17);
    h18->setNode(hexa18);
    h19->setNode(hexa19);

    /* Add nodes to the 'nodes' vector of the current object */
    this->nodes.push_back(v1);
    this->nodes.push_back(v2);
    this->nodes.push_back(v3);
    this->nodes.push_back(v4);
    this->nodes.push_back(v5);
    this->nodes.push_back(v6);
    this->nodes.push_back(v7);
    this->nodes.push_back(v8);
    this->nodes.push_back(v9);
    this->nodes.push_back(v10);
    this->nodes.push_back(v11);
    this->nodes.push_back(v12);
    this->nodes.push_back(v13);
    this->nodes.push_back(v14);
    this->nodes.push_back(v15);
    this->nodes.push_back(v16);
    this->nodes.push_back(v17);
    this->nodes.push_back(v18);
    this->nodes.push_back(v19);
    this->nodes.push_back(v20);
    this->nodes.push_back(v21);
    this->nodes.push_back(v22);
    this->nodes.push_back(v23);
    this->nodes.push_back(v24);
    this->nodes.push_back(v25);
    this->nodes.push_back(v26);
    this->nodes.push_back(v27);
    this->nodes.push_back(v28);
    this->nodes.push_back(v29);
    this->nodes.push_back(v30);
    this->nodes.push_back(v31);
    this->nodes.push_back(v32);
    this->nodes.push_back(v33);
    this->nodes.push_back(v34);
    this->nodes.push_back(v35);
    this->nodes.push_back(v36);
    this->nodes.push_back(v37);
    this->nodes.push_back(v38);
    this->nodes.push_back(v39);
    this->nodes.push_back(v40);
    this->nodes.push_back(v41);
    this->nodes.push_back(v42);
    this->nodes.push_back(v43);
    this->nodes.push_back(v44);
    this->nodes.push_back(v45);
    this->nodes.push_back(v46);
    this->nodes.push_back(v47);
    this->nodes.push_back(v48);
    this->nodes.push_back(v49);
    this->nodes.push_back(v50);
    this->nodes.push_back(v51);
    this->nodes.push_back(v52);
    this->nodes.push_back(v53);
    this->nodes.push_back(v54);

    // Adding paths to the vector of paths
    this->paths.push_back(path1);
    this->paths.push_back(path2);
    this->paths.push_back(path3);
    this->paths.push_back(path4);
    this->paths.push_back(path5);
    this->paths.push_back(path6);
    this->paths.push_back(path7);
    this->paths.push_back(path8);
    this->paths.push_back(path9);
    this->paths.push_back(path10);
    this->paths.push_back(path11);
    this->paths.push_back(path12);
    this->paths.push_back(path13);
    this->paths.push_back(path14);
    this->paths.push_back(path15);
    this->paths.push_back(path16);
    this->paths.push_back(path17);
    this->paths.push_back(path18);
    this->paths.push_back(path19);
    this->paths.push_back(path20);
    this->paths.push_back(path21);
    this->paths.push_back(path22);
    this->paths.push_back(path23);
    this->paths.push_back(path24);
    this->paths.push_back(path25);
    this->paths.push_back(path26);
    this->paths.push_back(path27);
    this->paths.push_back(path28);
    this->paths.push_back(path29);
    this->paths.push_back(path30);
    this->paths.push_back(path31);
    this->paths.push_back(path32);
    this->paths.push_back(path33);
    this->paths.push_back(path34);
    this->paths.push_back(path35);
    this->paths.push_back(path36);
    this->paths.push_back(path37);
    this->paths.push_back(path38);
    this->paths.push_back(path39);
    this->paths.push_back(path40);
    this->paths.push_back(path41);
    this->paths.push_back(path42);
    this->paths.push_back(path43);
    this->paths.push_back(path44);
    this->paths.push_back(path45);
    this->paths.push_back(path46);
    this->paths.push_back(path47);
    this->paths.push_back(path48);
    this->paths.push_back(path49);
    this->paths.push_back(path50);
    this->paths.push_back(path51);
    this->paths.push_back(path52);
    this->paths.push_back(path53);
    this->paths.push_back(path54);
    this->paths.push_back(path55);
    this->paths.push_back(path56);
    this->paths.push_back(path57);
    this->paths.push_back(path58);
    this->paths.push_back(path59);
    this->paths.push_back(path60);
    this->paths.push_back(path61);
    this->paths.push_back(path62);
    this->paths.push_back(path63);
    this->paths.push_back(path64);
    this->paths.push_back(path65);
    this->paths.push_back(path66);
    this->paths.push_back(path67);
    this->paths.push_back(path68);
    this->paths.push_back(path69);
    this->paths.push_back(path70);
    this->paths.push_back(path71);
    this->paths.push_back(path72);

    /* Adding each hexa to the hexas vector of the board */
    this->hexas.push_back(h1);
    this->hexas.push_back(h2);
    this->hexas.push_back(h3);
    this->hexas.push_back(h4);
    this->hexas.push_back(h5);
    this->hexas.push_back(h6);
    this->hexas.push_back(h7);
    this->hexas.push_back(h8);
    this->hexas.push_back(h9);
    this->hexas.push_back(h10);
    this->hexas.push_back(h11);
    this->hexas.push_back(h12);
    this->hexas.push_back(h13);
    this->hexas.push_back(h14);
    this->hexas.push_back(h15);
    this->hexas.push_back(h16);
    this->hexas.push_back(h17);
    this->hexas.push_back(h18);
    this->hexas.push_back(h19);

}

/**
 * @brief Destructor
 */
Board::~Board()
{
    // Deleting development cards and clearing the map
    for (auto &card : cards)
    {
        delete card.first;
    }
    cards.clear();

    // Deleting nodes
    for (auto node : nodes)
    {
        delete node;
    }
    nodes.clear();

    // Deleting paths
    for (auto path : paths)
    {
        delete path;
    }
    paths.clear();

    // Deleting hexas
    for (auto hexa : hexas)
    {
        delete hexa;
    }
    hexas.clear();
}

/**
// Get the node at a specific index.
// @param i The index of the node.
// @return Node* Pointer to the node at index `i`.
// @throws std::out_of_range if the index is out of range.
*/
Node *Board::getNodeAt(int i)
{
    if (i < 0 || i >= static_cast<int>(nodes.size()))
    {
        throw std::out_of_range("Node index out of range");
    }
    return nodes[i];
}

/**
 *  Get the path at a specific index.
    @param i The index of the path.
    @return Path* Pointer to the path at index `i`.
    @throws std::out_of_range if the index is out of range.
 */
Path *Board::getPathAt(int i)
{
    if (i < 0 || i >= static_cast<int>(paths.size()))
    {
        throw std::out_of_range("Path index out of range");
    }
    return paths[i];
}
/*
// Get the hexagon at a specific index.
// @param i The index of the hexagon.
// @return Hexa* Pointer to the hexagon at index `i`.
// @throws std::out_of_range if the index is out of range.
*/
Hexa *Board::getHexaAt(int i)
{
    if (i < 0 || i >= static_cast<int>(hexas.size()))
    {
        throw std::out_of_range("Hexa index out of range");
    }
    return hexas[i];
}

/**
// Pick a random development card.
// @return DevelopmentCard* Pointer to a random development card.
 */
DevelopmentCard *Board::pickRandomDevCard()
{
    if (cards.empty())
    {
        return nullptr;
    }

    std::vector<DevelopmentCard *> validCards;

    // Collect pointers to cards with count > 0
    for (const auto &card : cards)
    {
        if (card.second > 0)
        {
            validCards.push_back(card.first);
        }
    }

    if (validCards.empty())
    {
        return nullptr;
    }

    // Select a random card from validCards
    int randomIndex = rand() % validCards.size();
    DevelopmentCard *pickedCard = validCards[randomIndex];

    // Decrement the count of the card
    cards[pickedCard]--;

    // Return a copy of the card that has been picked
    return pickedCard->copyCard();
}


/**
    Print the current state of the board.
    This method prints out information about the nodes and their associated tiles.
 */
void Board::printinf()
{
    for (auto node : nodes)
    {
        node->printinf();
    }
}
