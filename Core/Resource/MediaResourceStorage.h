#ifndef GRAPHICSRESOURCESTORAGE_H_INCLUDED
#define GRAPHICSRESOURCESTORAGE_H_INCLUDED

namespace Game {


class MediaResourceStorage {
protected:
    GraphicsObject **graphicsObjects;
    AudioObject **audioObjects;
public:
    MediaResourceStorage() {
    }

    GraphicsObject *getGraphicsObject(int identifier) {
        return graphicsObjects[identifier];
    }

    AudioObject *getAudioObject(int identifier) {
        return audioObjects[identifier];
    }
};

}


#endif // GRAPHICSRESOURCESTORAGE_H_INCLUDED
