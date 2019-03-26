하위버전 Vector 사용을 위해 앱 app단 gradle에 아래를 적는다.
```
vectoreDrawables.useSupportLibrary = true
```
Layout에서 접근할 때 `app:srcCompat="@drawable/ic_location_on_black_24dp"`으로 지정한다.
