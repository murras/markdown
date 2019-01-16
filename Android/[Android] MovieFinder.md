https://www.themoviedb.org/settings/api 가입
API 얻어낸다.

RecyclerView를 이용.
AsyncTask : 네트워크 사용하기 때문에
Glide : 이미지 처리
OkHttp
GSon

인터넷 사용 허가를 받기 위해 아래 추가.
> AndroidManifest.xml
```xml
<uses-permission android:name="android.permission.INTERNET"/>
```

사용할 라이브러리 추가.
> build.gradle(app)
```
implementation 'com.android.support:recyclerview-v7:28.0.0'
implementation 'com.github.bumptech.glide:glide:3.7.0'
implementation 'com.squareup.okhttp3:okhttp:3.11.0'
implementation 'com.google.code.gson:gson:2.8.5'
```

참고 : [RecyclerView](https://developer.android.com/guide/topics/ui/layout/recyclerview)
> activity_main.xml
```xml

```
> list_item.xml
```xml

```

- Request로 받는 json 데이터 파일의 이름
> Movie.java
``` java

```