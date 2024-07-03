#include <iostream>
#include <string>

using namespace std;

class Artist {
protected:
    string name;
public:
    Artist(const string& name) : name(name) {}
    virtual ~Artist() {}

    virtual string getType() const = 0;

    string getName() const {
        return name;
    }
};

class Musician : public Artist {
public:
    Musician(const string& name) : Artist(name) {}

    string getType() const override {
        return "musician";
    }
};

class Band : public Artist {
private:
    Musician* members[10];
    int memberCount;
public:
    Band(const string& name) : Artist(name), memberCount(0) {}

    bool addMember(Musician* musician) {
        if (memberCount < 10) {
            members[memberCount++] = musician;
            return true;
        }
        return false;
    }

    string getType() const override {
        return "band";
    }
};

class Song {
private:
    string title;
    Artist* performer;
    Artist* writer;
public:
    Song(const string& title, Artist* performer, Artist* writer) :
        title(title), performer(performer), writer(writer) {}

    string getTitle() const {
        return title;
    }

    Artist* getPerformer() const {
        return performer;
    }

    Artist* getWriter() const {
        return writer;
    }
};

class Track {
private:
    Song* song;
    int bitrate;
    int duration; 
public:
    Track(Song* song, int bitrate, int duration) :
        song(song), bitrate(bitrate), duration(duration) {}

    Song* getSong() const {
        return song;
    }

    int getBitrate() const {
        return bitrate;
    }

    int getDuration() const {
        return duration;
    }
};

class Album {
private:
    string name;
    Track* tracks[20]; 
    int trackCount;
public:
    Album(const string& name) : name(name), trackCount(0) {}

    bool addTrack(Track* track) {
        if (trackCount < 20) {
            tracks[trackCount++] = track;
            return true;
        }
        return false;
    }

    string getName() const {
        return name;
    }
};

int main() {
    Musician shamoon("shamoon");
    Band jal("Jal");
    jal.addMember(&shamoon);

    Song song1("bikhra hu mai", &jal, &shamoon);

    Track track1(&song1, 320, 180);

    Album album("aadat");
    album.addTrack(&track1);

    cout << "Album: " << album.getName() << endl;
    cout << "Track 1: " << track1.getSong()->getTitle() << " by " << track1.getSong()->getPerformer()->getName() << endl;

    return 0;
}