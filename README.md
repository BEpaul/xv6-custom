# xv6-custom

## 목표
- System call 함수 추가 (getnice, setnice, ps)
- 스케줄링 기법 변경 (Round Robin -> Linux CFS)

## 상세 설명
### System call
- getnice: 타겟 프로세스의 nice value를 반환
- setnice: 타겟 프로세스의 nice value를 설정
- ps: 모든 프로세스의 현황 출력 (test에서 유용하게 사용)

### Scheduling
- yield 함수를 이용하여 스케줄러 구현
- Round Robin -> CFS (Completely Fair Scheduling)

## 실행 방법 
- 실행 환경: Linux

```Shell
    # Run xv6
    $ cd xv6-public
    $ make qemu-nox
    # run the test code
    $ mytest

    # Terminate xv6
    ctrl + 'a' -> 'x'
```