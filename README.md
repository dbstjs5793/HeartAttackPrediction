# Heart Attack Prediction
# 심장병 예측 프로그램

이 프로젝트는 AVR 보드를 활용하여 심장병 여부를 예측하는 프로그램입니다. 사용자로부터 환자의 데이터를 입력받아 심장병 여부를 진단합니다.

## 기술 스택
- **AVR 보드**
- **VSPE**와 **PuTTY**를 사용한 **UART 통신**
- **Kaggle 데이터셋**
- **Scikit-learn**, **PyTorch**를 활용한 모델 구축 및 성능 최적화

## 실행 방법
1. 데이터셋을 다운로드하고, 모델을 훈련시킵니다.
2. AVR 보드를 연결하고, 통신 프로그램을 실행하여 진단 결과를 확인합니다.

## 프로젝트 구성
- `convert_svm.py` : svm 예제 코드
- 
- `model.py`: 심장병 예측 모델
- `data/`: Kaggle 데이터셋
- `README.md`: 프로젝트 설명

## 라이선스
MIT License
