function func = input_linear( ~ )
%INPUT_LINEAR ���Ժ�������
% �����Ի������벢��ȡ����Ҷ����䣬���Ժ�����k��bֵ
    prompt = {'Please enter lower limit:','Please enter upper limit:','Please enter k:','Please enter b'};
    func = inputdlg(prompt,'Linear Parameter',1,{'0','100','1','0'},'on');
end