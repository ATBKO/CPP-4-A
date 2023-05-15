#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include <cmath>

using namespace ariel;

// Test suite for the class "Point"
TEST_SUITE("Point class test"){

    // Test case for the constructors of the class "Point"
    TEST_CASE("Constructor"){

        // Check if no exceptions are thrown when creating a "Point" object with no arguments
        CHECK_NOTHROW(Point());

        // Check if no exceptions are thrown when creating a "Point" object with integer coordinates
        CHECK_NOTHROW(Point(12, 11));

        // Check if no exceptions are thrown when creating a "Point" object with a float and an integer
        CHECK_NOTHROW(Point(0.6, 7));

        // Check if no exceptions are thrown when creating a "Point" object with an integer and a float
        CHECK_NOTHROW(Point(4, 0.22));

        // Check if no exceptions are thrown when creating a "Point" object with large integer coordinates
        CHECK_NOTHROW(Point(98762, 123123));
    }

    // Test case for the methods of the class "Point"
    TEST_CASE("Methods"){

        // Create some "Point" objects for testing
        Point a(123, 123);
        Point b(862, 827);
        Point a1(0.4, 123);
        Point b1(0, 0.1);
        Point a2(0, 0);
        Point b2(99, 99);
        Point a3(5, 58);
        Point b3(1, 2);

        // Subcase for testing the "distance" method of the class "Point"
        SUBCASE("Distance method"){

            // Check if the distance between two points a and a1 equals the distance between points b and b1
            CHECK_EQ(a.distance(a1), b.distance(b1));

            // Similar checks for other point combinations
            CHECK_EQ(a1.distance(a2), b1.distance(b1));
            CHECK_EQ(a2.distance(b1), b2.distance(a3));

            // Checks with known distances
            CHECK_EQ(a3.distance(b3), 10);
            CHECK_EQ(a2.distance(b2), 5);
            CHECK_EQ(a1.distance(b1), 0);

        }

        // Subcase for testing the "moveTowards" method of the class "Point"
        SUBCASE("MoveTowards method"){

            // Check if no exceptions are thrown when moving point a towards point b
            CHECK_NOTHROW(a.moveTowards(b));

            // Similar checks for other point combinations
            CHECK_NOTHROW(a1.moveTowards(b1));
            CHECK_NOTHROW(a2.moveTowards(b2));
            CHECK_NOTHROW(a3.moveTowards(b3));
        }
    }
}


TEST_SUITE("Character class"){

    TEST_CASE("Cowboy class"){

        SUBCASE("Constructor"){
            CHECK_NOTHROW(Cowboy("a", Point(986,123)));
            CHECK_NOTHROW(Cowboy("b", Point(0.99,0)));
            CHECK_NOTHROW(Cowboy("c", Point(2,0.12)));
            CHECK_NOTHROW(Cowboy("d", Point(12367,15)));
        }

        SUBCASE("Methods"){
            Cowboy* a = new Cowboy("a", Point(986,123));
            Cowboy* b = new Cowboy("b", Point(0.99,0));
            Cowboy* c = new Cowboy("c", Point(2,0.12));
            Cowboy* d = new Cowboy("d", Point(12367,15));

            // from character
            SUBCASE("isAlive"){
                CHECK_NOTHROW(a->isAlive());
                CHECK_EQ(a->isAlive(), true);

                CHECK_NOTHROW(b->isAlive());
                CHECK_EQ(b->isAlive(), true);

                CHECK_NOTHROW(c->isAlive());
                CHECK_EQ(c->isAlive(), true);

                CHECK_NOTHROW(d->isAlive());
                CHECK_EQ(d->isAlive(), true);
            }
            SUBCASE("hit"){
                CHECK_NOTHROW(a->hit(50));
                CHECK_NOTHROW(b->hit(99));
                CHECK_THROWS(b->hit(12));
                CHECK_NOTHROW(c->hit(0));
                CHECK_THROWS(d->hit(110));
            }
            SUBCASE("getName"){
                CHECK_EQ(a->getName(), "a");
                CHECK_EQ(b->getName(), "b");
                CHECK_EQ(c->getName(), "c");
                CHECK_EQ(d->getName(), "d");
            }
            SUBCASE("getLocation"){
                CHECK_NOTHROW(a->getLocation());
                CHECK_NOTHROW(b->getLocation());
                CHECK_NOTHROW(c->getLocation());
                CHECK_NOTHROW(d->getLocation());
            }

            SUBCASE("shoot"){
                CHECK_NOTHROW(a->shoot(b));
                CHECK_NOTHROW(b->shoot(a));
                CHECK_NOTHROW(c->shoot(d));
                CHECK_NOTHROW(d->shoot(c));

                CHECK_THROWS(a->shoot(a));
                CHECK_THROWS(b->shoot(b));
                CHECK_THROWS(c->shoot(c));
                CHECK_THROWS(d->shoot(d));
            }
            SUBCASE("hasboolets"){
                CHECK_NOTHROW(a->hasboolets());
                while(a->hasboolets()){
                    a->shoot(b);
                }
                CHECK_EQ(a->hasboolets(), false);

                CHECK_NOTHROW(c->hasboolets());
                while(c->hasboolets()){
                    c->shoot(d);
                }
                CHECK_EQ(c->hasboolets(), false);
            }
            SUBCASE("print"){
                CHECK_NOTHROW(a->print());
                CHECK_NOTHROW(b->print());
                CHECK_NOTHROW(c->print());
                CHECK_NOTHROW(d->print());
            }
        }
    }

    TEST_CASE("Ninja class"){
        SUBCASE("constructors"){
            CHECK_NOTHROW(Ninja("a", Point(1,1), 100, 80));
            CHECK_NOTHROW(Ninja("b", Point(0.1,1), 0, 100));
            CHECK_NOTHROW(Ninja("c", Point(1,0.1), 150, 0));
            CHECK_NOTHROW(Ninja("d", Point(1.5,2.9), 0, 0));
        }

        SUBCASE("functions"){
            Ninja* a = new Ninja("a", Point(1,1), 150, 20);
            Ninja* b = new Ninja("b", Point(0.1,1), 100, 40);
            Ninja* c = new Ninja("c", Point(1,0.1), 50, 0);
            Ninja* d = new Ninja("d", Point(1.5,2.9), 0, 100);

            // from character
            SUBCASE("isAlive"){
                CHECK_NOTHROW(a->isAlive());
                CHECK_EQ(a->isAlive(), true);

                CHECK_NOTHROW(b->isAlive());
                CHECK_EQ(b->isAlive(), true);

                CHECK_NOTHROW(c->isAlive());
                CHECK_EQ(c->isAlive(), true);

                CHECK_NOTHROW(d->isAlive());
                CHECK_EQ(d->isAlive(), true);
            }
            SUBCASE("getName"){
                CHECK_EQ(a->getName(), "a");
                CHECK_EQ(b->getName(), "b");
                CHECK_EQ(c->getName(), "c");
                CHECK_EQ(d->getName(), "d");
            }
            SUBCASE("getLocation"){
                CHECK_NOTHROW(a->getLocation());
                CHECK_NOTHROW(b->getLocation());
                CHECK_NOTHROW(c->getLocation());
                CHECK_NOTHROW(d->getLocation());
            }

            SUBCASE("slash"){
                CHECK_NOTHROW(a->slash(b));
                CHECK_NOTHROW(b->slash(c));
                CHECK_NOTHROW(c->slash(d)); 
                CHECK_NOTHROW(d->slash(a));
            }
            SUBCASE("print"){
                CHECK_NOTHROW(a->print());
                CHECK_NOTHROW(b->print());
                CHECK_NOTHROW(c->print()); 
                CHECK_NOTHROW(d->print());
            }
            
        }
    }

    TEST_CASE("OldNinja class"){
        OldNinja* a = new OldNinja("a", Point(8632,7125));

        SUBCASE("constructors"){
            CHECK_NOTHROW(OldNinja("a", Point(8632,7125)));
            CHECK_NOTHROW(OldNinja("b", Point(123,55)));
            CHECK_NOTHROW(OldNinja("c", Point(0.2,42897)));
            CHECK_NOTHROW(OldNinja("d", Point(3,0)));
        }

        SUBCASE("hit"){
            CHECK_NOTHROW(a->hit(10));
            CHECK_NOTHROW(a->hit(90));
            CHECK_THROWS(a->hit(1));
        }
    }

    TEST_CASE("YoungNinja class"){
        YoungNinja* a = new YoungNinja("a", Point(897312,31231));

        SUBCASE("constructors"){
            CHECK_NOTHROW(YoungNinja("a", Point(23,1)));
            CHECK_NOTHROW(YoungNinja("b", Point(0.6,0.6)));
            CHECK_NOTHROW(YoungNinja("c", Point(99,0.9)));
            CHECK_NOTHROW(YoungNinja("d", Point(1,9)));
        }

        SUBCASE("hit"){
            CHECK_NOTHROW(a->hit(12));
            CHECK_NOTHROW(a->hit(55));
            CHECK_THROWS(a->hit(2));
        }
    }

    TEST_CASE("TrainedNinja class"){
        TrainedNinja* a = new TrainedNinja("a", Point(73,122));

        SUBCASE("constructors"){
            CHECK_NOTHROW(TrainedNinja("a", Point(73,122)));
            CHECK_NOTHROW(TrainedNinja("b", Point(0.5,5)));
            CHECK_NOTHROW(TrainedNinja("c", Point(77,0.2)));
            CHECK_NOTHROW(TrainedNinja("d", Point(0.9,0.9)));
        }

        SUBCASE("hit"){
            CHECK_NOTHROW(a->hit(99));
            CHECK_NOTHROW(a->hit(111));
            CHECK_THROWS(a->hit(2));
        }
    }
}

TEST_SUITE("Teams class"){
    Cowboy *c = new Cowboy("cowboy", Point(2,2));
    OldNinja *on = new OldNinja("old_ninja", Point(2,2));
    YoungNinja *yn = new YoungNinja("young_ninja", Point(2,2));
    TrainedNinja *tn = new TrainedNinja("trained_ninja", Point(2,2));

    TEST_CASE("Team class"){
        SUBCASE("constructors"){
            CHECK_NOTHROW(Team team1(c));
            CHECK_NOTHROW(Team team2(on));
            CHECK_NOTHROW(Team team3(yn));
            CHECK_NOTHROW(Team team4(tn));
        }

        SUBCASE("functions"){
            Team* team_a = new Team(c);
            Team* team_b = new Team(on);
            SUBCASE("add"){
                CHECK_NOTHROW(team_a->add(yn));
                CHECK_NOTHROW(team_b->add(tn));
            }
            SUBCASE("attack"){
                CHECK_NOTHROW(team_a->attack(team_b));
                CHECK_NOTHROW(team_b->attack(team_a));
            }
            SUBCASE("stillAlive"){
                CHECK_NOTHROW(team_a->stillAlive());
                CHECK_NOTHROW(team_b->stillAlive());
            }
            SUBCASE("print"){
                CHECK_NOTHROW(team_a->print());
                CHECK_NOTHROW(team_b->print());
            }
        }
    }

    TEST_CASE("Team2 class"){
        SUBCASE("constructors"){
            CHECK_NOTHROW(Team2 team5(c));
            CHECK_NOTHROW(Team2 team6(on));
            CHECK_NOTHROW(Team2 team7(yn));
            CHECK_NOTHROW(Team2 team8(tn));
        }

        SUBCASE("functions"){
            Team2* team_a = new Team2(c);
            Team2* team_b = new Team2(on);
            SUBCASE("add"){
                CHECK_NOTHROW(team_a->add(yn));
                CHECK_NOTHROW(team_b->add(tn));
            }
            SUBCASE("attack"){
                CHECK_NOTHROW(team_a->attack(team_b));
                CHECK_NOTHROW(team_b->attack(team_a));
            }
            SUBCASE("stillAlive"){
                CHECK_NOTHROW(team_a->stillAlive());
                CHECK_NOTHROW(team_b->stillAlive());
            }
            SUBCASE("print"){
                CHECK_NOTHROW(team_a->print());
                CHECK_NOTHROW(team_b->print());
            }
        }
    }

    TEST_CASE("SmartTeam class"){
        SUBCASE("constructors"){
            CHECK_NOTHROW(SmartTeam team9(c));
            CHECK_NOTHROW(SmartTeam team10(on));
            CHECK_NOTHROW(SmartTeam team11(yn));
            CHECK_NOTHROW(SmartTeam team12(tn));
        }

        SUBCASE("functions"){
            SmartTeam* team_a = new SmartTeam(c);
            SmartTeam* team_b = new SmartTeam(on);
            SUBCASE("add"){
                CHECK_NOTHROW(team_a->add(yn));
                CHECK_NOTHROW(team_b->add(tn));
            }
            SUBCASE("attack"){
                CHECK_NOTHROW(team_a->attack(team_b));
                CHECK_NOTHROW(team_b->attack(team_a));
            }
            SUBCASE("stillAlive"){
                CHECK_NOTHROW(team_a->stillAlive());
                CHECK_NOTHROW(team_b->stillAlive());
            }
            SUBCASE("print"){
                CHECK_NOTHROW(team_a->print());
                CHECK_NOTHROW(team_b->print());
            }
            SUBCASE("getEnemy"){
                CHECK_NOTHROW(team_a->getEnemy(team_b));
                CHECK_NOTHROW(team_b->getEnemy(team_a));
            }
        }
    }
    
}

TEST_SUITE("game"){

    TEST_CASE("classic game"){
        // Set up initial positions for cowboys
        Point a(32.3,44),b(1.3,3.5);

        // Create cowboys and ninjas
        Cowboy *Lop = new Cowboy("Lop", a);
        OldNinja *Tip = new OldNinja("Tip", b);

        // Create teams and add members
        Team team_A(Lop);
        team_A.add(new YoungNinja("Alice", Point(52,123)));

        Team team_B(Tip);
        team_B.add(new OldNinja("Bob", Point(12,81)));

        // Start the game loop until one team is defeated
        while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
            CHECK_NOTHROW(team_A.attack(&team_B));
            CHECK_NOTHROW(team_B.attack(&team_A));
        }

        // Verify the result of the game
        CHECK(team_A.stillAlive() > 0);    // At least one member of team A is still alive
        CHECK(team_B.stillAlive() == 0);   // All members of team B are defeated
    }

    TEST_CASE("different type of teams game"){
        SUBCASE("team vs team2"){
            // Set up initial positions for cowboys
            Point a(32.3,44),b(1.3,3.5);

            // Create cowboys and ninjas
            Cowboy *alex = new Cowboy("Alex", a);
            OldNinja *debi = new OldNinja("Debi", b);

            // Create teams and add members
            Team2 team_A(alex);
            team_A.add(new YoungNinja("Tomi", Point(12,55)));

            Team team_B(debi);
            team_B.add(new OldNinja("Poul", Point(44,0.9)));

            // Start the game loop until one team is defeated
            while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
                CHECK_NOTHROW(team_A.attack(&team_B));
                CHECK_NOTHROW(team_B.attack(&team_A));
            }

            // Verify the result of the game
            CHECK(team_A.stillAlive() > 0);    // At least one member of team A is still alive
            CHECK(team_B.stillAlive() == 0);   // All members of team B are defeated
        }
    }
}


