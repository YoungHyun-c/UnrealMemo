/*
과제1. 슬기로운 포트폴리오 구성
- 3D 포트폴리오는 기본적으로 준비 기간이 아주 오래 걸린다.
ㄴ 퀄리티 있는 포폴에 한하여.

- 미리 준비를 해야한다.... 오늘부터 게임 선정해놓기.
-> 선정했으면 리소스가 잘 되는지 확인.
-> 모작 or 지갑 워리어?
-> 1. 맵, 파티클, 이펙트, 쉐이더 -> 코드가 들어가는 얘들이라 잘 안보인다.

UEV <- 언팩킹 툴
유니티 익스트랙터


- 조심.. 매우 조심..
오픈월드, 템포가 빠른 액션 게임, 대전 게임, 빌더류, 턴제 게임(회사에선 좋아하지만, 구현 난이도가 높음)
ㄴ + 그냥 봐도 알고리즘 덩어리들...


과제2. 앞으로의 로드맵 작성 및 제출
- 4신기를 앞으로 어떻게 공부할지 본인의 패턴에 맞춰 로드맵을 만든다.
ㄴ + 포폴 일정 (간략하게)

-> 코딩 테스트 풀어보고, 본인이 몇단계까지 가능한지 로드맵 문서 1페이지에 기입하여 제출 할 것.

-> 메일로 제출 (명일 9시까지)
 ㄴ 양식 : 언리얼 3기_공부 로드맵_이름
 ㄴ 파일명 : 언리얼 3기_공부 로드맵_이름.pdf
 ㄴ 내용 : 특이사항 기입.

*/

// 9/11
/*
과제 1. 포트폴리오 후보군 선정.

- 3개의 후보군을 선정할 것.
 ㄴ 실패를 가정해서, 장르의 다양성을 추구하면 좋다.

- 차주에 기획서 작성이 있을 예정이니 참고할 것.

3DMax, 마야, 블렌더에 되는지 확인.
 

※ 행렬 공부(+, -, *, 역, 3 x 3, 4 x 4)]
크기 곱셈.
회전 곱셈.
위치 덧셈.

항등 행렬 : 벡터를 행렬에 곱했을 때 똑같은 벡터가 나오는 것.
크기 행렬 : 벡터를 곱했을 때 크기가 커지거나 줄어들게 한다.
이동행렬 : 벡터를 행렬에 곱했을 때, W만큼 적용 받아 이동하도록 한다.


※ 벡터의 내적 / 외적
벡터의 덧셈 -> 위치를 이동시킬 때 쓴다.
벡터의 뺄셈 -> A 위치에서 B 위치로 이동시키는 방향을 만들 때 쓴다.
곱셈 -> 여러 가지 종류가 있다. float 하나랑 곱하여 벡터의 크기를 키울 수 있다.
나눗셈 -> 크기를 줄일 수 있다.
덧셈과 뺄셈의 관계, 곱셈과 나눗셈의 관계는 역함수 관계이다.

벡터의 외적 => 벡터 * 벡터 인데 특정한 규칙으로 곱해주는 공식이다.
-> 결과는 또 다른 수직인 벡터가 나오게 되는데 그것으로 앞면과 뒷면을 알 수 있다.
-> 바라보는 방향과, 바라봐야 할 방향을 외적해서 회전해야 할 방향도 알 수 있다. 음수 : 시계방향, 양수 : 반시계 방향

*/

// 9 / 12
/*
- 연계 과제 -
과제1. 에디터와 친해지시오.

- 에디터의 기본적인걸 활용하여, 고퀄리티 모형을 제작해 오시오.
	ㄴ 모형의 종류 : 자동차 / 탱크 / 헬리콥터 / 집

- 기본도형으로만 구현을 원칙
 ㄴ 이외에는 사용 X

-색상 및 텍스처는 추가해 올 필요 없다.

택 1일
- 01. 자동차는 바퀴 / 탱크는 상부와 하부 (+포탑 / 포신) / 헬리콥터는 프로펠러 / 집은 담벼락이 있는 구조로 만들 것.

- 02. 자동차만 + 집은 담벼락이 있는 구조로 만들 것.

*/

// 9/19
/*
과제 1. 지하실 환경 구축

- 깊이는 2층
ㄴ B1 : 차고지 / B2 : 라이트맵이 첨부된 지하실

- 문은 3개 이상 만들어 온다.
ㄴ 밀고 당기고 / 옆으로 / 위로 올라가는

※ 주의점 : 크게 크게 큼지막하게 아주 크게 만들어 온다.

*/

// 9/20
/*
- 로직 구현용
과제1. 블루프린트 활용

- 새로운 스테이지를 구성한다.
- 플레이어와 상호작용이 가능한 오브젝트 배치
ㄴ 오브젝트의 종류는 총 3가지
- 플레이어가 엑터를 먹으면 점수가 올라간다.
ㄴ 20 / 30 / 40

- 일정 점수가 되면 게임 클리어 조건 달성
ㄴ 조건 : 100 점 + 각 오브젝트 종류별 2개이상씩 먹었나로 판별
- 클리어 조건을 달성한 상태에서 특정 위치로 이동하면 레벨 전환 -> 클리어 된 화면에서는 특정 위치로 이동하면 다시 게임이 재시작한다.

- UI X
- String으로 처리해 올것.

- 확인용
과제2. 작업 진행률 확인
- .txt 파일에 기입.
- 포함되야 될 내용.
ㄴ 게임명 : 
ㄴ 게임 장르 :
ㄴ 리소스 진행상황:
 ㄴ 1. 맵 / 이펙트 + 파티클 어떻게 할것인지.
 ㄴ 2. 모델
 ㄴ 3. 애니메이션
 ㄴ 4. 사운드
ㄴ 현재 진행상황 :
 ㄴ 본인이 판단한 전체 진행 사항 : % 기입
 ㄴ 설계 및 생각 :
  ㄴ 설계를 어떻게 할 것인지 / 어디부터 어떻게 어떤 것을 중점적으로 만들고 핵심 요소로 무엇을 보여줄 것인지?

양식 :
메일 제목 : 언리얼 3기_직업 현황_이름
첨부파일 : 언리얼 3기_작업 현황_이름.txt
내용 : 특이사항 기입

※ 제출 : 차주 월요일 9시까지

*/


// 9 / 23
/*
25일까지 (수)
중간 평가 2차. 코인 먹기

- 탑 뷰에서 진행되는 게임 구조

- 스테이지는 미로 형태의 맵을 구성한다.

- 맵에는 코인이 배치되어 있고 코인을 다 먹으면 게임 종료.
 ㄴ 종료가 될때는 캐릭터를 조명으로 하이라이트 시키며 종료한다.

 - 룰 : 10개의 코인을 먹어야 하고 남은 코인이 5개 이상일시 남은 갯수를 알려준다.
  ㄴ 디버그 스크린 / 로그 처리
  ㄴ 5개 이하일시 맵의 조명이 어두워 지고 남은 코인은 위치를 특정하기 쉽게
  색상이 들어간 조명 + 다이나믹 머터리얼 처리를 한다.
  ㄴ 맵에 폭탄 오브젝트도 추가할 것.
   ㄴ 폭탄을 먹으면 목표 코인에서 + 1 (최대 코인 1개 + 코인을 1개 새로 생성)
*/

// 9 / 24
/*
과제1. 중간 평가 결과물 제출

- 명일 09시 까지

- 양식
 ㄴ 메일 제목 : 언리얼 3기_2차 중간 평가_이름
 ㄴ 첨부 파일 : 언리얼 3기_2차 중간 평가_이름.zip
	ㄴ. 01. 프로젝트.zip / 02. 실행 결과물 -> 실행 화면01, 실행 화면 02, 실행 화면 03.
 ㄴ 메일 내용 : 특이사항 기입 및 실행화면 캡처 3장 첨부 (파일 첨부 아님)
 
과제2. 상호작용 응용

- 아래의 조건에 맞는 로직을 구현하고 완성한다.
ㄴ 1. 원형 트랙을 만들고 타고 다닐 수 있는 플랫폼 구현.
 ㄴ 트리거 될시 자동으로 트랙을 따라 움직인다.
ㄴ. 2. 트리거 되면 오망성 모양으로 이동하는 플랫폼 구현.
- 도전과제.
ㄴ 3. 지형에 상관없이 움직일 수 있는 플랫폼 구현 (타고 다닐 수 있는)
 ㄴ 지상 + 하늘 (드래곤볼 군두운)


*/