# Heart Attack Prediction
# 심장병 예측 프로그램

이 프로젝트는 AVR 보드를 활용하여 심장병 여부를 예측하는 프로그램입니다. 사용자로부터 환자의 데이터를 입력받아 심장병 여부를 진단합니다.

## 기술 스택
- **AVR 보드**
- **VSPE**와 **PuTTY**를 사용한 **UART 통신**
- **Scikit-learn**, **PyTorch**를 활용한 모델 구축 및 성능 최적화

## 실행 방법
1. Kaggle에서 데이터셋을 다운로드
2. Scikit-learn 라이브러리를 활용하여 SVM 모델 생성
3. UART 통신을 통해 예
4. AVR 보드를 연결하고, 통신 프로그램을 실행하여 진단 결과를 확인합니다.

## 프로젝트 구성
- `convert_svm.py` :  Convert libsvm datset to .csv file Use Python library ‘Numpy’ (참고를 위한 기본 예제코드)
  ㄴLibsvm(kaggle에서 가져온 dataset) 과 sklearn-svm(프로젝트에서 사용할 포멧)은 dataset format 차이가 있어 변환해줘야함
- `convert_svm_numpy.py` : Convert libsvm datset to .csv file Use Python library ‘Numpy’ (프로젝트에서 사용한 코드)
- `heart_model_poly.h`: 심장병 예측 모델
- `data/`: Kaggle 데이터셋
- `README.md`: 프로젝트 설명

## 라이선스
MIT License
