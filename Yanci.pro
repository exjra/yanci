QT += quick network core widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        rcontroller.cpp \
        rgameclient.cpp \
        rgameobject.cpp \
        rgamer.cpp \
        rresultpart.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    Yanci_tr_TR.ts

HEADERS += \
    rcontroller.h \
    rgameclient.h \
    rgameobject.h \
    rgamer.h \
    rresultpart.h

android {
#    QMAKE_LFLAGS += -nostdlib++

    QT += androidextras

    defineReplace(droidVersionCode) {
        segments = $$split(1, ".")

        for (segment, segments): vCode = "$$first(vCode)$$format_number($$segment, width=3 zeropad)"

        contains(ANDROID_TARGET_ARCH, arm64-v8a){
            suffix = 2
            message(android for arm64)
        }
        contains(ANDROID_TARGET_ARCH, armeabi-v7a){
            suffix = 0
            message(android for armv7a)
        }

        # add more cases as needed
        return($$first(vCode)$$first(suffix))
    }

    VERSION = 1.0.0

    ANDROID_VERSION_NAME = $$VERSION

    ANDROID_VERSION_CODE = $$droidVersionCode($$ANDROID_VERSION_NAME)

    message(automated version code is: $$ANDROID_VERSION_CODE)

    DISTFILES += \
        android/AndroidManifest.xml \
        android/build.gradle \
        android/gradle/wrapper/gradle-wrapper.jar \
        android/gradle/wrapper/gradle-wrapper.properties \
        android/gradlew \
        android/gradlew.bat \
        android/res/values/libs.xml

    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}
