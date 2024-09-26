#pragma region 01
/*
Question
CodingInterview

01. 언리얼 설치?

◆ 트윈모션?
 ㄴ 포폴할때 필요한 경우가 생길 수 있다.
 ㄴ 리얼타임 3D 렌더링 구조 (시각화)

 02. VS 설치.
 ㄴ 2019 : 매크로를 사용 가능한 버전.
 ㄴ 2022 : 확장도구 플러그 인 사용 가능. Visual Studio Integration Tool
 -> 언리얼은 2022 쓸꺼임.

 03. 서브 에디터
  ㄴ VS Code / NotePad++ 설치

 04. 엔진 수업에 한계...
  ㄴ 집중 혹은 질문

 05. 포트폴리오 얘기
*/
#pragma endregion

// 9 / 11
#pragma region 02 9 / 11
/*
▶ 엔진?
-> 상용 / 자체

★★★
-> 엔진을 뭐라고 생각하는지? (정의?)
ㄴ 라이브러리 + 툴(에디터) -> 라이브러리의 집합이라 할 수 있고, 편리하게 사용하기 위한 툴
 ㄴ 언리얼3 / 크라이 엔진
 
-> 너희가 바라보고 있는 방향성
ㄴ 2D ? / 3D -> 수학과 물리로 귀결된다.

★
▶ 그래픽 프로그래밍
-> DX / OpenGL
 ㄴ 둘의 차이점? (이동 / 회전 / 전방) 이 다름. -> 작동 방식이 다르다.
 -> 좌표계가 다르다
 -> 왼손 좌표계는 회전축이 시계방향으로 돈다. (DX)
 -> 오른손 좌표계는 회전축이 반시계방향으로 돌아 음수값이 들어간다. (Op)
 -> 언리얼은 왼손 좌표계를 쓰는데, 왼손이나 오른손으로 스위칭 할 수 있다는게 중요하다.
 -> 왼손 : F(Z : Yaw) ( 1, 0, 0) / R(X : Roll) (0, 1, 0) / U(Y : ptich) (0, 0, 1)
  ㄴ 월드 매트릭스-> 
   ㄴ SRT, TRS
   ㄴ T이동 R회전 S비율 (월드에서의 객체의 속성값)
   TRS 월드 좌표 -> 절대좌표 -> 공간값이 바뀌지 않는 절대적 좌표.
   SRT 로컬 좌표 -> 상대좌표 -> 월드에 속해 있지만, 나 자신의 좌표.



★★★★★★★★★★
▶ 렌더링 파이프라인

 - 3D -> 2D

 -> 상용 엔진은 기본적으로 만드는 프로그램에 따라 효율적인 렌더링 파이프라인을 별개로 제공한다.
  ㄴ EX : Bullet-in / SRP / URP / HDRP(hign dynamic pipeline) 

 -> 파이프라인 -> 세부적인 내용은 조금씩 바뀐다.
 ㄴ 단, 큰 틀은 X

 -> Fixed Pipeline (정) / Programmable PipeLine (동)
  ㄴ 둘의 차이점으로는 GPU의 사용 여부.
  ㄴ 쉐이더의 값을 요구하는 경우가 많다.

 -> DX 9 / DX 10 / DX 11 / DX 12(의 순기능은 레이트레이싱)

 01. 로컬 스페이스
  ㄴ 0, 0, 0 절대 좌표. 디자인의 영역.

 02. 월드 스페이스
  ㄴ 가상의 3D 공간을 만든다. (SRT) 순서
  ㄴ 월드상 -> 정점 좌표

 03. 뷰
 ㄴ 일반적 -> 카메라
 ㄴ 가상의 3D 공간 -> 배치된 오브젝트를 실제 눈으로 보기 위해
 ㄴ ★ 이때 카메라를 기준으로 월드 -> 뷰 스페이스 좌표계로 투영이 발생.

 04. 백
 ㄴ 백 스페이스
 -> 후면 추려내기

 05. 조명
 -> 무덤, 공정
  ㄴ 최적화 라인
  ㄴ 크게 난반사 / 정반사
  ㄴ 여기서 다시 나누면 크게  4가지 Point(손전등) / Directional(태양) / Spot(정점) / Ambient(주변광)
   ㄴ 다시 여기서 4가지로 분기
    ㄴ Ambient / Diffuse(확산광) / Specular(반사광) / Emissive(방출)

 06. 클리핑
 ㄴ 카메라 안에 들어오는 것에 그리지 않겠다.
 ㄴ 오클루전 / 프러스텀
 -> 원하는 부분을 자르겠다.

 07. 프로젝션 (투영)
 ㄴ 3D -> 2D 표현을 얻는 과정
  ㄴ Perspective, Orsorgraphic

 - Perspective (원근)
 ㄴ 원근감 (크기에 따라 바뀌는 것)
 ㄴ 카메라 앞으로 올수록 스케일을 위 아래로 늘려 원근감 부여.

 - Orsographic (직교)
 ㄴ 오브젝트를 원근감 없이 수직 위에서 내려다 보듯이 투영.

 -> 클리핑 결과로 3D 좌표에서 2D 좌표계로 행렬 변환

 isometric -> 등축 투영법 물체를 눕힌것.

 08. 뷰포트
 ㄴ 뷰포트에 맞게 투영된 2D 좌표계를 매칭 시키는 작업
 ㄴ 모니터 화면으로 올려준다.

 09. 보간 (레스터 라이즈)
 ㄴ 폴리곤 -> 픽셀

 ==========================================

 01. IA

 02. 정점

 03. 헐

 04. 터셀레이터


*/
#pragma endregion


// 9 / 12
#pragma region 03 9 / 12
/*
-> 기본적으로 알아둬야 할 사항.

-> 언리얼 엔진 -> 상용 엔진 -> 렌더링 엔진

-> 현업 -> 엔진 파트에서는 보통 디자이너 / 프로그래밍 파트로만 나뉜다.

-> 디자이너 + 프로그래밍 = TA

-> 엔진을 잘 쓰고 싶다. -> 엔진 구조 파악 -> 언어, 수학 + 그래픽스
 ㄴ 라이브러리 + 툴(에디터) + 피직스s + FMOD(사운드 라이브러리 엔진) = 언리얼

- 언리얼 엔진은 기존의 포멧과 좌표축이 다르다.

-> 뷰포트 좌표계 기준으로 좌하단 (API 좌상단)
-> 왼손 좌표계 / SRT 
-> 엔진은 왜 혼합형(DX, OpenGL)으로 되어있나? OpenGL 플랫폼 때문에 사용하기 위해선 컨버팅해야됨
-> 언리얼은 DX 기반이지만, OpenGL도 혼합 가능.
OpenGL은 상용화가 잘 되어있음. (자판기, 에어컨 화면)

-> 각 객체들은 월드라는 공간을 가진다.
 ㄴ 이는 트랜스폼으로 표현.
 ㄴ 월드 -> 뷰 -> 프로젝션

 -> 언리얼은 최적화를 할 때 신경을 써야 할 점이 많지만 일단 기본적으로 정점에 대한 계산을
 항상 염두해 둬야 한다. (엔진 -> 렌더링 -> 정점 세이더)

 -> 필요에 의해서 포폴 -> 쉐이더 들어가면 좋지만 안들어 갈 시 -> 다른 기능으로 대체.

 
 - 아웃라이너

 - 검색에 관한 문법

 - 1. 그냥 (일반검색)
  ㄴ EX : Light

 - 2. - (일치하는 놈 제외)
  ㄴ EX : -Light

 - 3. + (정확하게 일치하는 놈)
  ㄴ EX : +Light

 - 4. "" (정확 -> 이름 및 소문자)
  ㄴ EX : "Light"

  폴더 중요
  1. ~~~_BP.unproject
  2. Content 폴더 : 메테리얼, 파일 컨텐츠에서 건들지 말 것.
  3. Config 폴더 : 지우면 안됨. 사용자의 매크로키 등 설정이 들어있음, 지우면 초기상태.
  4. Intermediate : 위와 동일. (작업하던것(탭, 작업창) 유지할지)
  5. Saved : 없어도 상관은없지만, 개인 작업물에 영향을 끼침
  ★ _BP.uproject와  Content만 살아있어도 살릴 가능성이 있음. ★

  DerivedDataCache : 지워도됨. (작업 찌꺼기)


  Json을 알아야됨!
  Json 파일을 수정하고, 설정해야되기 때문에 사용할 줄 알아야됨.
  ▶ JSON (JavaScript Object Notation)
  -> 제이슨은 객체의 구조와 속성을 텍스트 형식으로 전달하기 고안되었다.
  -> 제이슨에 초기 정보가 있디 깨문에 uproject파일을 클릭하거나 상호 작용 했을때 윈도우가 이를 인식하고
  처리를 해주는 것. (해당 되는 엔진 버전 + 해당 되는 플러그 인 + 초기화 필요한 모듈)
  -> 제이슨은 객체의 구조 + 속성을 텍스트 형식으로 전달하기 때문에 일단 항상 평균 이상의 퍼포먼스를 낼 수 있다.
  ㄴ + 확장성 좋고 (#include Json.hpp) (헤더와 CPP 합쳐놓은게 hpp)
  ㄴ + 텍스트 형식이 -> 사람도 좋고
  ㄴ + 문자열 기반이기 때문에 오버헤드가 적다.
  ㄴ + 자료형에 특별한 제한이 없다. -> 특히 컴퓨터의 변수값을 표현하는데 좋다.
  -> 제이슨 자체는 자바 스크립트로 만들었지만 프로그래밍 언어나 플랫폼에 독립적 -> 다양한 언어에서 사용 가능
  -> 항상 비교직군으로 떠오르는 CSV(알아야됨),를 기준으로 자름. / XML / HTTP 보다 일반적인 상황에서 더 좋은 퍼포먼스 보여준다. (strtok)
  ㄴ XML vs json

  -> 제이슨을 사용할때는 개발자가 일반적으로 직렬화 / 역직렬화 작업을 해줘야 한다.

  -> 현업에서 직렬화 / 역직렬화를 사용해야 하는 이유
  ㄴ 네트워크 데이터를 주고 받을 때 네트워크 스트림은 일반적인 바이너리 데이터만 보낼 수 있기 때문.

  {
  "FileVersion": 3,
    "Plugins": 
    [
        {
            "Name": "ModelingToolsEditorMode",
            "Enabled": true,
            "TargetAllowList": 
            [
                "Editor"
            ]
        }
    ]
  }

  {}: 객체
  키: 값-> 객체가 가질 속성
  "": 문자열 데이터
  []: 배열

               (비트나 바이트를 받음)
  클라 < --- > 서버
        동기화
      동기화를 해주기 위해서 직렬화, 역직렬화가 들어간다.


 언리얼
 -> 초기
 -> 파일 -> 새레벨 -> Basic
 -> 작업할때는 오른쪽 세팅-> 엔진 퀄리티 세팅 -> 중간옵션. -> 나중에 게임할때는 에픽
 -> 프레임 확인 -> 왼쪽 화면 삼 =_ 에서 FPS 표시 클릭
 -> 창 -> 엑터 배치, 메시지 로그, 출력 로그, 콘텐츠 브라우저 1, 2 두개 띄우기 (Ctrl + Space)
 -> 툴 -> 클래스 배치
 모드
 -> 라이팅 포함
 -> 언릿 -> 라이팅 끄기
 -> 와이어 프레임 -> 프레임이 떨어지면 정점이 많은거 확인해보기.
 -> 라이팅만 -> 빛 사용하는 것만
 -> 리플렉션 -> 거울? 모드
 -> 게임세팅 -> Ev100 -> 나중에 화면이 밝아지거나 어두워지는 효과 낼때 사용 (코드로 Export하기)
 프로젝트 복제
 -> 만들었던 프로젝트 -> 우클릭 -> 복제
 -> 생성 -> 계속
 -> 복제된 것 -> 우클릭 -> 폴더 보기 -> uproject파일이름변경 -> Config파일 -> DefaultEngine ->
 -> 맨위에
 [URL]
 GameName=Example 적음.
 그다음 상위 폴더로 가서, 폴더의 이름 Example로 변경 저장. -> 에픽게임즈 라이브러리 가서 보면 바뀌어있음.

*/
#pragma endregion

#pragma region 9 / 13
/*
▶ 효율은 모르겠지만 좋은 퀄리티를 보여주는 언리얼

- 장점
-> 멀티 플랫폼 지원 (크로스) 지원
-> 통합 개발 환경 지원 (IDE)
-> 빌드 및 모듈 시스템 (플러그 인)
-> 통합 에셋 관리 시스템 지원 (추상 팩토리)
ㄴ 오브젝트의 선언과 관리 시스템
-> 스크립팅 시스템 지원 (에디터 / 런)
-> 파티클 시스템 지원
-> 렌더링 시스템지원
-> 2D 시스템 지원
-> 셰이더 시스템 지원
-> 사운드 시스템 지원 (Fmod)
-> 물리 시스템 지원 (phys x)
-> 지형 시스템 지원 
-> 프로파일링 시스템 지원 
-> 마켓 플레이스 지원
-> 애니메이션 시스템 지원
-> 머터리얼 에디터 지원
- 5 한정 -> 나나이트 / 루멘

- 단점
-> 많이 많이 무겁다.
-> 많이 많이 느리다.
-> 입문 난이도가 높다.
 ㄴ 선행 지식이 많이 요구됨.
-> 활성화된 커뮤니티 없음. (만약 찾는 기능이 없으면 유니티로 대체해서 검색해서 찾아봐야 한다)

※ 언리얼 엔진은 C++ 스크립트를 통해 컴포넌트 프로그래밍 방식을 지원한다.
▶ 컴포넌트 프로그래밍
-> 기존 상속 기반 프로그래밍의 단점을 극복하기 위한 프로그래밍 방식
-> 상속 기반이 물체를 정의한 기능을 확장 시켜나가는 개념을 지닌것에 비해 컴포넌트 기반 프로그래밍은
기능을 모음으로서 물체를 정의하는 방식으로 접근한다.
-> 이러한 방식은 곧 덕 타이핑 개념이라고 불린다.

▶ 덕 타이핑 (Duck Typing) (STL 개념으로 만들어져 있어 써봤다)
-> 동적 타이핑의 한 종류라고 생각하면 된다.
ㄴ 객체의 변수 및 매서드의 집합이 객체의 타입을 결정하는 것을 뜻한다. (행위도 결정할 수 있다)
-> 프레임워크 설계가 정말 중요하다.
Managed 와 UnManged 차이? 메모리 관리 주체 (컴퓨터 or 나) (RIL / T-S ?) 포인터 -> * 나
Managed(컴퓨터) 가비지 컬렉션
UnManaged(나) T-S 나 -> * 포인터- > 로우/하이?

-> 장점 (부위파괴?)
-> 상속 기반 프로그래밍이 유연하지 못하다.
-ㄴ 확장에 있어 유연하지 못함.
-> 반면 컴포넌트 방식을 기능을 추가함으로 새로운 객체를 표현하기 때문에 상속 기반 방식보다 좀 더
유연한 클래스 구조 설계를 가능하게 한다.
-> 런타임에 극강한 장점을 얻을 수 있다.

-> 단점
-> 컴포넌트 방식을 객체를 표현하기 위한 기능, 각 클래스 별로 분리되어 있는 경우가 많기 때문에
컴포넌트간에 서로 협력 관계를 형성하기 위한 로직이 필연적으로 필요하다.
-> 이는 상속에 비해 많은 유연성을 제공하지만 퍼포먼스 측면에서는 좋지 않다.
-> 구현 난이도가 높다. (언리얼에서 어느정도 제공은 하지만 만들어보면 확장이 안되고, 오류수정하기 힘들것이다)
-> 런타임 자료형 오류가 발생할 순 있다.

▶언리얼 엔진에서의 컴포넌트 기반 프로그래밍
-> 언리얼 엔진은 컨테이너에 해당하는 게임 객체 (Actor)와 EngineCore 클래스를 통해 컴포넌트 방식을
제어하는 매커니즘으로 동작한다.
-> 일반적으로 언리얼의 메모리 관리 시스템부터 에디터와의 연동을 원한다면 반드시 UObject 파생 클래스를
직 / 간접적으로 상속해야지만 언리얼 객체상에 구동하는 것이 가능하다.


- 재질 (Material)
- 머터리얼은 기본적으로 Suface에 적용할 수 있는 미리 빌드된 비주얼 이펙트라고 할 수 있다.
ㄴ 텍스처 / 색상 / 거칠기 / 빛 등 모든 서피스 디테일에 관여할 수 있다.

-> 3D 외형을 설정하기 위한 주요 수단이라고 이해하면 좋겠다.
-> 여기서는 이미지 기반 반사부터 표현에 이르기까지 모든것을 머터리얼로 처리 할 수 있고, 셰이더 처리 또한
여기서 발생한다.
-> 재질 교체를 위해서는 머터리얼을 사용하자.

머터리얼, 모델, 애니메이션 이 3가지는 계속해서 괴롭힐 것이다.

선이 깜빡이는 이유
-> Z - Fighting
서로 동일한 위치값이 들어와, Depth를 지정해주지 않으면 서로 어떤게 렌더링이 될지 서로 렌더 하기 때문에 겹치는 선이 깜빡인다.
해결 방법.
1. 렌더링 우선 순위 부여 (추천하진 않음)
2. 컬링 (할 수 는 있지만 효율은 모르겠다)
3. 거리 확보 (
4. 정수 (정수값을 주면 Z-Fighting이 사라질것이다.)

Metalic-> 반사값.
Roughness -> 표면 거칠기.
ㆍRoughness (캐릭터를 불렀을때, 명암이 이상하게 들어가있으면 이게 설정 안되어있어서 그럴수 있다)
깊이감을 줄때 사용하는 속성

※ 기능적으로는 동일
-유니티
-> Smoothness
ㄴ 매끄러운 정도
-언리얼
Roughness
ㄴ 거칠기 정도 (1에 가까워 질수록 거칠어 진다.)

Mesh (3D -> 중요) (최적화)
1. V vertex -> S.M (Static Mesh) 정적 매쉬
 2D 정점 / 3D 정점
 (X,Y의 위치 좌표만 있음 / X, Y위치 부터 시작해서, UV 색상 등 여러 가지 정보를 가지고 있다)
2. E Edge (모서리)
3. P Polygon (면)
4. M Mesh  Polygon이 모여 만들어진것이 3D 공간상의 물체라고 할 수 있다.
흔들리는 나무, 풀 밭 -> 스태틱 매쉬임 (눈속임)

bsp란?
복셀, 오페인?
다음 수업에 물어볼 것.

UV(언리얼) <-> 타일링(유니티) -> vertex(정점이 갖고있다)
-> Textrue -> 매핑에 쓰는 좌표계
UV 값으로 확대, 축소 반복, 미러링, 클래핑 을 할 것인지 설정할 수 있다.

정점의 Pos는 3차원, UV는 2차원.
3D UV를 만드려면 큐브차원이 필요하다.
텍스처의 UV값을 임의로 줄여서(ex) 0.5, 1) 사용하면, 그려질때는 다시 1, 1로 확장하기 때문에
텍스처의 색깔이 연해진다.
-> 리소스를 가져와서 텍스처를 매핑했을때 제대로 안나오면, UV값의 문제일 수 있다.

UV 주의사항
-> 확대 OK (면에 1장이 들어가서)
-> 축소에는 옵션을 지정해서 -> 컴퓨터에게 알려주어야 한다.
ㄴ 반복해서 바를지 / 밀어서 바를지 / 거울처럼 반사 시킬건지 / 아니면 색상으로 채울것인지
★
- DX + OpenGL (애니메이션에서도 자주 나올것이다)
ㄴ 랩(반복) / 클램프(비반복) / 보더(도장같이 찍겠다) /
미러(역으로 반사해서 바른다.) / 컬러 (남은 컬러 피커로 처리)


언리얼 조작
3인칭 캐릭터 만들기.
-> 콘텐츠 브라우저 -> 추가 -> 피처 또는 콘탠츠 팩 추가.
-> 삼인칭.
-> 추가 되었으면, 시작 버튼 왼쪽에 코드모양 누르기
-> 프로젝트 세팅 -> 게임모드Base클래스 선택 -> BP_ThirdPersonGameMode 
플레이어 안움직일경우) 시작 버튼 오른쪽 : 설정 눌러서 -> 선택된 뷰포트인지 확인.
-> 좌표를 안보고 싶으면 -> 표시 -> 그리드 체크 해제.

메테리얼 설정->
우클릭 -> VectorParam ->  Meterial_plane 채우기
우클릭 -> ScalarParam -> Metalic_plane 채우기
우클릭 -> ScalarParam -> Rouhness_Plane 채우기

*/
#pragma endregion

#pragma region 9/19
/*
LOD https://dev.epicgames.com/documentation/ko-kr/uefn/setting-the-level-of-detail-in-unreal-editor-for-fortnite
-> 카메라 기존 거리에 따른 텍스처의 매끄러움 정도.
-> 카메라 기존 거리에 따라 텍스처를 줄이거나 늘릴지 적용하는 정도.
0 ~ 3까지 0일수록 해상도를 가장 높인다.
라이트맵 -> 음영 
Bake(굽는다) 메모리 사용량.
랜더했을때 쳐낼꺼 쳐내고, 스태틱 매쉬로 바꾸고 라이팅 작업을 해줘야함.

▶ 블루 프린트 (Blueprint Visul Scripting)
-> 블루프린트란 비주얼 스크립팅 -> 노드 기반 스크립팅 시스템.
ㄴ 코드로 작업을 노드라는 작업으로 연결시켜주는 것을 의미.
ㄴ 시각적인 그래프 기반 시스템으로 게임 플레이 메커니즘이나 인터렉션 로직을 구축 하는게 탁월.

- 블루 프린트는 엔진이 지원하는 가장 강력한 기능중에 1개
ㄴ 설계 단계 및 모듈화 레벨에서 높은 효율을 자랑한다.
-> C++ 스크립트와의 퍼포먼스 차이가 존재.

스크립트를 써야 되는 이유는 속도 때문! 블프 <-> 스크립트의 속도 차이는 10배 차이.
블루프린트에선 -> 쓰지 않을 것도 포함되어 있기 때문에 느리다. 하지만 시각적인 면에서 흐름도가 잘 나타나 있는 장점이 있다.

BP 와 C++
1. 면접에서 대답.
2. 선행지식 부족.
3. 설계 + 모듈화.
BP ->
1. 퍼포먼스 X (include를 다 하고 시작한다, 써야될 것을 미리 포함시켜야 되기 때문에 느리다.)
2. 타직군이 쓸 수 있게 해주는 에디터.
3. 애니메이션에서 주로 쓴다.

- 성능면도 그렇고 기능면에서도 코딩을 완전히 대체하기는 어렵다.

※ 결론
-> 편리한 IDE를 구축하기 위해 블루프린트와 C++ 스크립트를 적당히 섞어서 개발하면 좋다.
ㄴ 권장 (6)C++ : (4)블프

▶ 스크립트 언어
C++ 네이티브 != C++ 스크립트
- 스크립트 언어 -> 간이 언어
- 언리얼에서의 스크립트 언어는 커스텀하게 동작하는 별도의 로직을 작성하기 위한 컴포넌트.
ㄴ 스크립트는 엔진에서 제공되지 않는 기능을 구현하는 것이 가능.
- 스크립트 언어 == 간이 언어 -> 짧은 명령어 집합으로 보는게 맞다.
ㄴ 네이티브 언어보다 기능은 제한적이지만 프로그램을 쉽게 개발하고 배운데 특화되어 있는 언어들.
-> 스크립트 => 인터프리터.
ㄴ 컴파일(러) != 인터프리터.
인터프리터는 인터프리케이션이라는 객체가 있어서, 코드를 한 줄씩 읽어서 내려가며 실행하는 절차이다. -> 변경된 부분만 하나씩 읽는다.

- 언리얼은 유니티와 동일하게 핫 리로드 기능을 지원한다.
ㄴ + 라이브 코딩

ㆍ 라이브 코딩 P I E (Play In Editor) 컴파일 단계 / 런타임 (빠르다)
라이브 코딩은 런타임중에도 실시간으로 바이너리를 캐치해준다. (단, 불안정하다.)
-> 엔진이 실행되는 동안 어플리케이션의 C++ 코드를 리빌드하고 바이너리를 패치할 수 있는 시스템.
-> 플레이 테스트 섹션이나 에디터 작업에 방해하지 않고 C++ 클래스를 변경 및 컴파일 한다.
ㄴ 즉시 확인 할 수 있다는 장점도 존재.

-> 라이브 코딩 < = > 핫 리로드.
- 단점으로 디버깅이 좀 힘들다.
ㄴ 객체 트래킹이 힘들다.

ㆍ 핫 리로드 트래킹은 쉬운편(로그가 남아있기 때문에) 대신 정말 느리다.
- VS 빌드가 여기에 해당됨.
- 프로그래머가 생성한 결과물을 에디터가 감지할 수 있게 기준 모듈을 교체하는 것.
ㄴ 에디터에 교체된 모듈을 적용한다.
ㄴ 모듈은 덮어쓰기가 발생하지 않는다. -> 새로운 파일로 생성하고 에디터 종료시 임시 모듈을 날리는 방식으로 동작.

▶블루프린트 유형
- 블루프린트는 크게 3가지만 기억하면 된다.
ㄴ 쪼개서 쓸꺼면 기본적으로 레벨 / 클래스 / 애니메이션 / 데이터 / 인터페이스 / 매크로

1. 레벨 블루프린트
ㄴ 언리얼 -> 씬 -> 레벨이라고 한다.
ㄴ 생성한 해당 레벨에서 동작하는 블루프린트.
ㄴ 레벨마다 1개만 존재.
-> 게임의 룰을 지정하는 곳. 레벨(스테이지)에서의 조건. (플레이어의 Hp 관리를 여기서 해야 할까? NO) -> 플레이어가 죽으면 -> MSG를 레벨에 보낸다.
레벨은 그 레벨안에 존재하는 것의 모든 것을 알고있다.

2. 클래스 블루프린트
ㄴ 쉽게 생각해서 우리가 생각한 클래스
ㄴ 새로운 클래스나 엑터의 타입을 정의할 수 있고 이 엑터는 다른 엑터들과 동일하게 레벨 내에서 인스턴스 형태로 맵에
배치가 가능하다.
ㄴ 모든 레벨 / 게임 전체에서 사용할 수 있는 블루프린트
enum, class, struct, union


3. 애니메이션 블루프린트
ㄴ 폰이 사용 하는 블루프린트 (애니메이션 상호작용)

- 언리얼의 유형
- 엑터
ㄴ 월드에 배치 가능한 스폰 가능한 오브젝트라고 할 수 있다.

- 폰
ㄴ 빙의 할 수 있는 객체 + 컨트롤러부터 입력을 받는 "엑터"

- 캐릭터
ㄴ 걷기 / 달리기 / 점프 등의 기능을 할 수 있는 빙의 가능한 폰.

- 캐릭터 컨트롤러
ㄴ 플레이어가 사용하는 폰을 컨트롤하는 엑터

- 게임 모드
ㄴ 레벨에 존재하는 기본적인 게임 플레이를 정의하는 객체.



언리얼 수업.
엑터배치 (지오메트리 모드)
박스 ->
-> 왼쪽 상단 선택모드 -> 브러시 편집 모드
-> 박스의 모서리 선택시, 분할 선택가능.
-> 분할을 누르면 각 꼭지점을 눌러 변형 가능 (지붕 만들기)
실린더 ->
-> 브러시 타입 -> Subtractive
스피어 -> 스태틱 매쉬 생성.
-> 스태틱 매쉬 더블 클릭. -> 오른쪽 계산기 모양클릭(프로퍼티 매트릭스에서 선택열기)
-> Static Mesh 설정
-> 라이트 맵 해상도 (Resolution)값이 클수록 그림자가 줄어들고, 갑이 작을수록 그림자가 많아짐
-> 라이트 맵 좌표 (Coordinate Index, UV채널) 값을 1로 주어야 영향이 생김.

라이트 배치가능
Sky Atmosphere 추가시 전체적인 공간이 밝아짐
-> DirectionalLight에서 에트머스피어 선 라이트 체크를 해제 해주면, 전체광이 사라지고 SKyLight에만 영향 받음.
Point라이트 설치 (전체 주변광 ex 전구)
Rect라이트 설치 (사각형이 비추는 곳 밝아짐 ex 사각형전등)
이후 빌드 -> 라이트 빌드 및 라이트 디버그 창을 통해 확인가능

*/
#pragma endregion

#pragma region 9 / 20
/*
▶ 블루프린트 포인트 / 주의점
-> 내가 복잡한 설계 구조를 만들고 싶을 때 -> 블루프린트 X (쓰더라도 객체지향이 포함된 블루프린트)

-> 블루프린트는 기본적으로 다른 블루프린트와 관계없이 효율적이며 간결하게 작성하는게 좋다.
ㄴ 컴포넌트.

ㆍ 포인트
1. 속도
ㄴ 블루프린트에서 속도를 좀 챙기고 싶으면 함수화 작업을 해주는게 좋다.
ㄴ 함수화 작업이 완료 된 로직들은 디스패처 + 이벤트 + 델리게이트로 처리한다.
ㄴ OOP를 지키면 아주 좋다.
ㄴ 복사보다는 참조를 사용하는 습관

2. 컬러 스키마
ㄴ 회사마다 정해져 있다.
ㄴ 너희만의 기준점을 잡고 규약을 만들어 사용하면 좋다.
ㄴ 블루프린트는 결국 가독성이 최고이기 때문에 신경을 많이 써야 한다.



★★
Tick 이란? -> Update (Delta Second(인자로 들어오는 것))
프레임과 관련이 있는 이벤트
ㄴ 언리얼 -> 120 -> 120번

- 불완전 호출이기 때문에 리스크가 있다.
ㄴ 하드웨어의 영향을 받는다.

- 퍼포먼스 측면에서는 당연히 좋지 않다.

1. Update
ㄴ 초당 갱신되는 횟수

2. LateUpdate
ㄴ Update() -> LateUpdate()
LateUpdate가 돌아가기 위해선 Update의 선행 정보가 필요하다.
Update -> 플레이어, LateUpdate -> 카메라 ex) 캐릭터가 움직이고, 카메라가 따라 움직이는 것.

3. FixedUpdate
ㄴ Phy -> 물리 업데이트
ㄴ 프레임과는 별개로 동작 (시간 기반) 기본값 0.02초 마다 자동으로 호출

색상
1. 빨간색
ㄴ 이벤트
2. 파란색
ㄴ 함수
3. 흰색
ㄴ 흐름 제어


-> 블루프린트 기억해야 할 것.
- 이벤트
ㄴ 언제?

- 조건
ㄴ 실행될 조건

- 액션
ㄴ 어떤 행동을 취할것인가?

최적화
VFX ->
파티클 -> 입자기반 (GPU) -> LOD 
이펙트 -> 텍스처기반 (CPU)


언리얼
BP_Sample_01
-> Construction Script는 플레이어 생성자개념. 이벤트 그래프의 Begin에서 시작하면 늦음.
이벤트 그래프에 있는 것들은 이벤트 노드(빨간색), 사각형은 델리게이트를 받는 것.
델리게이트 -> 이벤트가 발생하면, 아웃풋을 받을 수 있다.
ED -> 이벤트가 발생했는지 다시 확인하는 것.
색상
1. 빨간색
ㄴ 이벤트
2. 파란색
ㄴ 함수
3. 흰색
ㄴ 흐름 제어

트리거용 Shape 만들기.
만들 폴더 위치에 우클릭 -> 블루프린트 클래스 -> 엑터
-> 만든 블루프린터 엑터 더블클릭, 들어간 창에 만들 Shape 모양 끌어다 놓기.
만든 Shape 눌러 디테일 -> 콜리전 프리셋의 BlockAllDynamic에서 OverlapDynamic으로 바꾸기(지나갈꺼라서)
위의 탭 창에 뷰포트로 되어있을텐데 -> 이벤트 그래프창 열기

*/
#pragma endregion

#pragma region 9 / 23
/*
▶ 씬 노드
- 한 씬에 포함되어 있는 노드들을 의미한다.

- 이 노드들은 기본적으로 어떤 경우에는 보이고 어떠한 경우에는 보이지 않는 경우가 생긴다.
ㄴ 이를 컬링이라고 관리한다.

ㆍ 컬링
- 라이트 연산과 더불어 최적화에 핵심

- 기본적으로 "드로우콜"을 줄이기 위해 눈에 보이지 않는 오브젝트를 제외한다는 개념.
ㄴ 이는 렌더링할 오브젝트의 수를 줄인다.
 ㄴ 렌더링하지 않을 오브젝트를 추려내는게 -> 컬링

드로우콜 -> 렌더링 1번
-> 여기서 2번, 3번 여러번 그리게 된다면 개발자가 정해놓은 우선순위가 발생하게 된다.
-> 적은게 베스트, 많으면 많을수록 떨어지게 된다.

★★★★★
ㆍ컬링의 종류(↑↑↑↑↑↑↑)
01. 백페이스 컬링
ㄴ 후면 -> Vector 개념, 방향이 나와야됨. -> 카메라가 바라보는 방향에 Normal Vector를 쏴서 소실점을 기준으로 중간값.
-> 매쉬 내의 버텍스의 노말 벡터 방향과 비교하고, 각도에 따라 쉐이딩 처리.
-> 노말 벡터를 이용해 앞인지 뒤인지를 확인해 카메라에서 보이지 않는 폴리곤을 렌더링하지 않는다.


02. 오클루전 컬링
ㄴ 엔진 디폴트
ㄴ 오브젝트가 다른 오브젝트에 의해 가려져서 카메라 뷰에서 보이지 않을 때 오브젝트에 대한 렌더링 비활성화
 ㄴ 오클루더 / 오클루디 => 오브젝트
 오클루더는 카메라에 포함된 오브젝트, 오클루디는 카메라에 포함되지 않은 오브젝트. 포함된 오브젝트를 렌더링 활성화 시키는 것.


03. 프로스텀 컬링.
ㄴ 계층 구조물 고려. (벽에 있는 문에 있는 창문)
오클루더와 프로스텀의 차이


04. 프론트(포워드) 컬링
ㄴ 앞면을 그린다..


※ LOD 포워드와 연관있음.

※ 결론적으로 드로우 콜 줄이려고 컬링을 사용한다.

언리얼
변수에서 지정할 수 있는 값.
Rotator -> 가상의 축 공간
네임 -> const char 라고 생각할 것 -> 빠르게 읽어올 수 있다, 최적화한 녀석 (string constant pool?)
OS에 들어가는 내용에 네임 타입을 사용하면 손해는 없다.
string은 불변이다?

스트링 -> 일반적인 string 객체

텍스트 -> UI에 표시되는 문자열.

for (int i = Index; i <= Last_Index; i++) 언리얼꺼는 크거나 같다는것에 주의
{

}

Make Literal int -> 임시 변수

ㆍ 머티리얼

머티리얼 :
ㄴ 실행전에 한번 -> 연산

머티리얼 인스턴스 :
ㄴ 런타임중에 연산이 되고 편집도 가능

※ 머티리얼은 유일 객체 / 머티리얼 인스턴스는 복제가 가능한 객체 (연산 비용 Low)

▶ 언리얼의 충돌
- 일반화된 단순 / 복합 크게 2종류가 있다.

- 콜리전 메시 유형

- 단순 구
ㄴ 구 형태로 생김

- 단순 캡슐
ㄴ 총알이나 캐릭터에 적용가능한 캡슐형

- 박스
ㄴ 일반적으로 적용할 수 있는 형태.

- 메시 콜리전
ㄴ 캐릭터(플레이어 한정) / 정밀도 => X (연산에서 아주 불리함 따라서 주 캐릭터에만 사용하는게 좋음)



*/
#pragma endregion


#pragma region 9 / 24
/*
▶ 타임라인
- 언리얼에서 주로 애니메이션을 통한 자연스러운 뭔가를 처리할 때 사용할 수 있는 특수 노드
ㄴ 보간이 기본적으로 들어가 있고 A + B 를 통해 동작하는 키 프레임 애니메이션

플랫폼 타임 (타임 라인)
-> 플레이 -> 현재 재생되는 시점부터의 정방향 실행 
-> Stop -> 정지
-> Reverse from End -> 타임라인 역방향 실행.
-> Set New Time -> 현재 재생 시간 실행
-> New Time -> 뭔가 반드시 실행 되어야 하는 개념.
-> Update -> 매 시간동안 실행 되는 것.
-> Finished -> 끝났을 때 딱 한 번 실행되는 것.

- 언리얼은 크게 2가지 애니메이션 기법
ㄴ 1. 타임라인 (보간을 통한 간단한 키 프레임 처리)
ㄴ 2. 애니메이션 블루프린트 (마티네 + 페르소나 확장형)
 ㄴ 아주 본격적 (스켈레탈 메시의 애니메이션 제어)

ㆍ 타임라인 언제 써야 할까?
- 간단한 값의 조작이나 변화를 다룰때 사용하면 베스트.
 ㄴ 예) 문 열기, 플랫폼 이동 등.

포폴할때 중요한 것 -> Transform, 애니메이션 다룰 수 있는 기법.

▶ 보간
- 사잇값을 구하는 수치 해석화
ㄴ v선형 / 이중선형 / v포물 / 다항 / v스플 / v구면 (포폴에선 선형과 구면은 무조건 들어가야 된다)

a. 선형 보간
 ㄴ 끝점이 있다고 가정했을 때 그 사이 값을 선형적으로 계산하는 방법.
 ㄴ 부드러운 처리와는 거리가 좀 멀다. (두 점사이를 직선으로 통과하기 때문)

b. 구면 보간 (애니메이션에 반드시 들어가야한다.)
 ㄴ 얻은 반지름이 보간된 거리.
 ㄴ 부드러운 처리가 가능하다. (애니메이션)
 
Lerp의 종류

Mathf.Lerp (포탄 + 오브젝트 객체 + 움직이는 객체들 에게 적용하는 연산식 보간)
ㄴ 트랜스폼 보다 가벼움. 트랜스폼 러프는 메세지 호출로 인해 느리므로 사용 X
Vector2.Lerp (트랜스폼)
Vector3.Lerp (트랜스폼)
Quaternion.Lerp (회전 전용) (q스칼라, A, B, T타임)
어떤 러프를 쓰는게 가장 좋은지 이해하고 있으면 된다.

Lerp(위치1, 위치2, T(0.0f))
ㄴ 위치 1
Lerp(위치1, 위치2, T(0.5f))
ㄴ 중간 위치
Lerp(위치1, 위치2, T(1.0f))
ㄴ 위치 2
WinApi에서 블렌더 SRC?에서 사용




*/
#pragma endregion

#pragma region 9 / 25
/*
PK란 (Packing kill) 관리 상태이며, 킬 대기 상태

1. DestroyActor 호출
2. 해당 객체를 객체에서 비활성화
3. Packing kill 영역으로 이동 (킬 대기) 기본 값으로 1분 대기


GC -> PK(관리) -> D

Destroy
EndKill -> 둘중 하나가 들어오면 Kill 대기상태(마킹) -> 제지(레벨) -> 마크업(클러스트링) -> GC Run
GCRun에서 (클러스팅 되어있는 메모리를 뺀다)
BeginDestroy(소멸시작) 반환 - 클러스터 메모리 공간을 깨끗이 비움.
is ReadyDestroy(소멸 마무리 준비) - 비운 메모리 공간을 반환.
FinishDistroy(소멸 마무리) - DC를 초기 상태(BC)로 반환.
클러스터? 힙과 스택을 연결하는   (언리얼의 생명주기? 동작 방식에 대해서 공부해보면 알 수 있을지도)

▶ C / C++ 언어의 메모리 동적 할당 시 주의사항
{
 * / & (로우 포인터, 언리얼에선 원시 포인터)
    - Premature Free (성급한 해제)

    1. 메모리 릭
    ㄴ 메모리 누수
    ㄴ 불필요한 메모리가 제거되지 않고 계속 상주한다.
     ㄴ 프로그래머에 의한 실수가 대부분.

    2. 댕글링 포인터
     ㄴ 제거 된 메모리를 가르키고 있는 경우
     ㄴ 더는 유효하지 않기 때문에 메모리 접근시 예측 불가능한 결과를 유발한다.
     ㄴ 주로 함수 / 클래스 / 추상 클래스 / 인터페이스 쪽에서 많이 발생한다.
      ㄴ 자동 변수를 가르키는 포인터의 반환 형태를 사용할때도 아주 많이 발생한다.
     -> 값만 빠진 곳을 가리켜 보면 16진수의 비트값이 나온다.
     -> 주소값이 빠졌을땐 가리키는 주소로 가지만, 다시 복귀할 주소가 없어서 프로그램 호출 지점으로 돌아갈 수 없다.
}

▶ 스마트 포인터
- C++ 에서 메모리 릭 방지 및 안전성 확보를 위해 사용
 ㄴ auto_ptr 대체하는 문법.
 
 - 포인터 처럼 동작하는 클래스 템플릿.
 - 원시 포인터가 실제 메모리를 가르키도록 초기화 하고 기본 포인터를 스마트에 대입하는 방식이 주로 사용된다.
 ㄴ new를 이용한 동적할당 기반.

 - 1 : 1 매칭을 원칙적으로 한다.
 - 사용했을때 이득은 속도면에서 유리하고, 유지보수에서 좋다.
  ㄴ 동적할당 자체가 생각보다 연산량이 높아.
   ㄴ 연산량이 높다 -> 여러번 할 것을 1번에 하면 좋다는 것.
 
 1. unique_tpr

 2. shared_ptr (1대1 호출을 풀어줄 수 있다)

 3. weak_ptr

 ※ 정의한 스마트 포인터의 라이프 사이클이 다하면 소멸자는 Delete 키워드를 통해 할당된 메모리를 자동 해제한다.
 ㄴ 그렇기 때문에 new 키워드가 반환하는 주소값을 스마트 포인터 대입을 시키면 따로 메모리를 해제 할 필요가 없어지는것.

 언리얼에서는 가비지 컬렉션이라는 것을 사용하여 메모리를 관리하는데, 프로그래머가 직접 메모리를 관리하고 싶은 객체가 있다면, 가비지 컬렉션에
 확인을 한 이후에 메모리 관리를 할 수 있다.

 ▶ UI / GUI / HUD 의 차이점
 - 2D + 3D에서 많이 사용하는 개념

ㆍ UI
- 유저 인터페이스라고 한다.
ㄴ 컴퓨터 / 모바일에 상호작용 가능한 시스템 정도라고 이해하면 베스트

Command LineInterface, (Text, Texture UI), Graphic
- CLI -> TUI -> GUI 형태로 발전을 했다.

- 언리얼에서는 GUI를 UMG라는 객체를 통해 표현한다.

ㆍUMG (Unreal Motion Graphic)
- 언리얼에서 지원하는 모션 그래픽
- 프로그래밍 언어를 모른다고 하더라도 메뉴 / HUD / 대부분의 UI를 구현 가능하게 하는 비주얼 툴
- GUI로 표현하는 대부분의 UI는 Canvas를 통해서 계층 구조를 잡고 부모와 자식으로 UI를 확장하는 경우가 대부분이다.
 언리얼이 지원하는 부분
1. 논 다이제틱 (디폴트)
 ㄴ 플레이어만 볼 수 있는 UI
    ㄴ EX : 체력바 / 메뉴 / 총의 조준점.
2. 다이제틱
 ㄴ 몰입형 UI -> 경험과 관련된 친구들이 이 다이제틱 UI에 할당이 된다.(다른 객체에 알려주기 위해 특화 되어있다.)
    ㄴ EX : 인벤토리

3. 스파셜
 ㄴ 지오메트리 내의 3D 공간에 표시되는 UI
  ㄴ EX : 화살표

4. 메타
 ㄴ 게임 속 이벤트의 추상적 표현이 들어갈때 표시되는 UI
    ㄴ 교체
    ㄴ 표현되는 UI를 어떻게 할 것인지.
     ㄴEX : 체력이 떨어졌을때 어떤 방법으로 떨어진 것을 알려줄지 (화면이 빨개지면서 깜빡이는 등)

ㆍ HUD
- Heads Up Display
- 정적 디스플레이
ㄴ 플레이어가 상호작용할 수 있는 UI
- 1, 2, 4

비Shipping


*/
#pragma endregion

#pragma region 9 / 26
/*
슬레이트는 픽셀 구조를 받아온다.

프레넬이란 화각 (반사에 따라 그려질 그림)
Normal(법선 벡터) -> 카메라로 직선 -> 출력 값 0
ㄴ 프레넬 0
 법선 -> 카메라 수직 -> 최대 1
ㄴ 최대치 프레넬
Fresnel
1. Exponentln (이펙트 감쇠)
2. BaseReflectFractionln (굴절율)
3. Normal

*/
#pragma endregion



#pragma region
#pragma endregion