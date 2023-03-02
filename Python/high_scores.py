class HighScores():
    def __init__(self, file_name:str) -> None:
        self.scores = {}
        self.file_name = file_name
        self.parse()

    def update(self, new_name:str, new_score:int):
        self.scores.append((new_score, new_name))
        self.scores = sorted(self.scores, reverse=True)
        scores_file = open(self.file_name,'w')
        for score,name in self.scores:
            scores_file.write(f'{score},{name}\n')
        scores_file.close()

    def parse(self):
        self.scores = []
        try:
            scores_file = open(self.file_name,'r')
            for line in scores_file.readlines():
                score, name = line.split(',')
                self.scores.append((int(score), name.removesuffix('\n')))
            scores_file.close()
        except FileNotFoundError: open(self.file_name, 'x').close()
    
    def show(self):
        print(''.center(9, '-')+''.center(18, '-')+''.center(11, '-'))
        print('|', 'Rank'.center(6), '|', 'Name'.center(15), '|', 'Score'.center(7), '|')
        print(''.center(9, '-')+''.center(18, '-')+''.center(11, '-'))
        index = 1
        for score,name in self.scores:
            print('|', str(index).center(6), '|', name.center(15), '|', str(score).center(7), '|')
            print(''.center(9, '-')+''.center(18, '-')+''.center(11, '-'))
            if index < 10: index += 1
            else: break
